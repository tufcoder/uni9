<?php
// db.php - Funções simples de acesso ao banco para login

require_once __DIR__ . '/connection.php';

function getUserByRA(PDO $pdo, string $ra) {
    $sql = "SELECT u.id, u.cpf, u.name, u.password "
         . "FROM users u "
         . "INNER JOIN students s ON u.id = s.user_id "
         . "WHERE s.ra = ?";
    $stmt = $pdo->prepare($sql);
    $stmt->execute([$ra]);
    return $stmt->fetch();
}

function getUserByCPF(PDO $pdo, string $cpf) {
    $sql = "SELECT id, cpf, name, password "
         . "FROM users "
         . "WHERE cpf = ?";
    $stmt = $pdo->prepare($sql);
    $stmt->execute([$cpf]);
    return $stmt->fetch();
}

function getUserIdByCPF($pdo, $cpf) {
  $stmt = $pdo->prepare("SELECT id FROM users WHERE cpf = ?");
  $stmt->execute([$cpf]);
  return $stmt->fetchColumn();
}

function getUserIdByRA($pdo, $ra) {
  $stmt = $pdo->prepare("SELECT u.id FROM users u INNER JOIN students s ON u.id = s.user_id WHERE s.ra = ?");
  $stmt->execute([$ra]);
  return $stmt->fetchColumn();
}

function clearFailedAttempts($pdo, $user_identifier, $ip) {
  $stmt = $pdo->prepare(
    "DELETE FROM login_attempts
     WHERE (user_identifier = ? OR ip_address = ?)
     AND success = 0
     AND attempt_time > NOW() - INTERVAL 15 MINUTE"
  );
  $stmt->execute([$user_identifier, $ip]);
}

function logLoginAttempt($pdo, $user_id, $user_identifier, $ip, $success) {
  if (empty($user_id)) {
    $user_id = null;
  }
  $stmt = $pdo->prepare("INSERT INTO login_attempts (user_id, user_identifier, ip_address, success, resolved) VALUES (?, ?, ?, ?, 0)");
  $stmt->execute([$user_id, $user_identifier, $ip, $success]);
}

function countFailedAttempts($pdo, $user_identifier, $ip, $minutes = 15) {
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

function authenticateUser($pdo, $idType, $idValue, $password) {
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

function getUser($pdo, $idType, $idValue) {
  if ($idType === 'ra') {
    return getUserByRA($pdo, $idValue);
  } elseif ($idType === 'cpf') {
    return getUserByCPF($pdo, $idValue);
  }
  return null;
}

function isPasswordValid($user, $password) {
  // Verifica hash de senha
  return isset($user['password']) && password_verify($password, $user['password']);
}
