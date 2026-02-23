<?php
require_once __DIR__ . '/db.php';

// Funções auxiliares
function getUserIdByCPF($pdo, $cpf)
{
  $stmt = $pdo->prepare("SELECT id FROM users WHERE cpf = ?");
  $stmt->execute([$cpf]);
  return $stmt->fetchColumn();
}

function getUserIdByRA($pdo, $ra)
{
  $stmt = $pdo->prepare("SELECT u.id FROM users u INNER JOIN students s ON u.id = s.user_id WHERE s.ra = ?");
  $stmt->execute([$ra]);
  return $stmt->fetchColumn();
}

function clearFailedAttempts($pdo, $user_identifier, $ip)
{
  $stmt = $pdo->prepare(
    "DELETE FROM login_attempts
     WHERE (user_identifier = ? OR ip_address = ?)
     AND success = 0
     AND attempt_time > NOW() - INTERVAL 15 MINUTE"
  );
  $stmt->execute([$user_identifier, $ip]);
}

function logLoginAttempt($pdo, $user_id, $user_identifier, $ip, $success)
{
  if (empty($user_id)) {
    $user_id = null;
  }
  $stmt = $pdo->prepare("INSERT INTO login_attempts (user_id, user_identifier, ip_address, success, resolved) VALUES (?, ?, ?, ?, 0)");
  $stmt->execute([$user_id, $user_identifier, $ip, $success]);
}

function countFailedAttempts($pdo, $user_identifier, $ip, $minutes = 15)
{
  $stmt = $pdo->prepare(
    "SELECT COUNT(*) FROM login_attempts
     WHERE success = 0
     AND resolved = 0
     AND (user_identifier = ? OR ip_address = ?)
     AND attempt_time > NOW() - INTERVAL ? MINUTE"
  );
  $stmt->execute([$user_identifier, $ip, $minutes]);
  return $stmt->fetchColumn();
}

// Lógica de autenticação simplificada
if ($_SERVER['REQUEST_METHOD'] === 'POST') {
  if (session_status() !== PHP_SESSION_ACTIVE) {
    session_start();
  }

  $ip = $_SERVER['REMOTE_ADDR'];
  $user_identifier = isset($_POST['cpf']) ? $_POST['cpf'] : (isset($_POST['ra']) ? $_POST['ra'] : $ip);
  $user_id = null;

  // Busca user_id se possível
  if (isset($_POST['cpf'])) {
    $user_id = getUserIdByCPF($pdo, $_POST['cpf']);
  } elseif (isset($_POST['ra'])) {
    $user_id = getUserIdByRA($pdo, $_POST['ra']);
  }

  // Verifica brute force
  $failCount = countFailedAttempts($pdo, $user_identifier, $ip);

  if ($failCount >= 5) {
    $error = 'Muitas tentativas falhas. Tente novamente em 15 minutos.';
    // Não registra logLoginAttempt durante bloqueio
  } else {
    // Validação CSRF
    if (!isset($_POST['csrf_token']) || !hash_equals($_SESSION['csrf_token'], $_POST['csrf_token'])) {
      $error = 'Token CSRF inválido.';
      if (!empty($user_identifier)) {
        logLoginAttempt($pdo, $user_id, $user_identifier, $ip, 0);
      }
    } else {
      $idType = isset($_POST['id-type']) ? $_POST['id-type'] : '';
      $password = isset($_POST['password']) ? $_POST['password'] : '';
      $idValue = '';

      if ($idType === 'ra' && isset($_POST['ra'])) {
        $idValue = $_POST['ra'];
      } elseif ($idType === 'cpf' && isset($_POST['cpf'])) {
        $idValue = $_POST['cpf'];
      }

      // Só registra tentativa se campos estão preenchidos
      if (empty($idValue) || empty($password)) {
        $error = 'Preencha todos os campos.';
        // Não registra tentativa
      } else {
        $result = authenticateUser($pdo, $idType, $idValue, $password);

        if ($result['user']) {
          $_SESSION['user'] = $result['user']['name'] ? $result['user']['name'] : $result['user']['cpf'];
          logLoginAttempt($pdo, $user_id, $user_identifier, $ip, 1);
          // Marca tentativas falhas recentes como resolvidas
          $stmt = $pdo->prepare(
            "UPDATE login_attempts
             SET resolved = 1
             WHERE (user_identifier = ? OR ip_address = ?)
             AND success = 0
             AND resolved = 0
             AND attempt_time > NOW() - INTERVAL 15 MINUTE"
          );
          $stmt->execute([$user_identifier, $ip]);
          header('Location: /home');
          exit;
        } else {
          $error = $result['error'];
          logLoginAttempt($pdo, $user_id, $user_identifier, $ip, 0);
        }
      }
    }
  }
}

function authenticateUser($pdo, $idType, $idValue, $password)
{
  if (empty($idValue) || empty($password)) {
    return ["user" => null, "error" => 'Preencha todos os campos.'];
  }

  if ($idType !== 'ra' && $idType !== 'cpf') {
    return ["user" => null, "error" => 'Selecione RA ou CPF.'];
  }

  $user = getUser($pdo, $idType, $idValue);

  if ($user && isPasswordValid($user, $password)) {
    return ["user" => $user, "error" => null];
  } else {
    $msg = $idType === 'ra' ? 'RA ou senha inválidos.' : 'CPF ou senha inválidos.';
    return ["user" => null, "error" => $msg];
  }
}

function getUser($pdo, $idType, $idValue)
{
  if ($idType === 'ra') {
    return getUserByRA($pdo, $idValue);
  } elseif ($idType === 'cpf') {
    return getUserByCPF($pdo, $idValue);
  }
  return null;
}

function isPasswordValid($user, $password)
{
  // Verifica hash de senha
  return isset($user['password']) && password_verify($password, $user['password']);
}
