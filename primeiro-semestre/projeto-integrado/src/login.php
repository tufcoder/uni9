<?php
require_once __DIR__ . '/db.php';

// Lógica de autenticação simplificada
if ($_SERVER['REQUEST_METHOD'] === 'POST') {
  if (session_status() !== PHP_SESSION_ACTIVE) {
    session_start();
  }

  $idType = isset($_POST['id-type']) ? $_POST['id-type'] : '';
  $password = isset($_POST['password']) ? $_POST['password'] : '';
  $idValue = '';

  if ($idType === 'ra' && isset($_POST['ra'])) {
    $idValue = $_POST['ra'];
  } elseif ($idType === 'cpf' && isset($_POST['cpf'])) {
    $idValue = $_POST['cpf'];
  }

  $result = authenticateUser($pdo, $idType, $idValue, $password);

  if ($result['user']) {
    $_SESSION['user'] = $result['user']['name'] ? $result['user']['name'] : $result['user']['cpf'];
    header('Location: /home');
    exit;
  } else {
    $error = $result['error'];
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
  return isset($user['password']) && $user['password'] === $password;
}
