<?php
require_once __DIR__ . '/db.php';

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
