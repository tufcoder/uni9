<?php
require_once __DIR__ . '/db.php';
// Lógica de autenticação, define $error se necessário
if ($_SERVER['REQUEST_METHOD'] === 'POST') {
  if (session_status() !== PHP_SESSION_ACTIVE) {
    session_start();
  }
  $idType = isset($_POST['id-type']) ? $_POST['id-type'] : '';
  if ($idType === 'ra' && isset($_POST['ra'])) {
    $ra = $_POST['ra'];
    $password = isset($_POST['password']) ? $_POST['password'] : '';
    if (!empty($ra) && !empty($password)) {
      $user = getUserByRA($pdo, $ra);
      if ($user && $user['password'] === $password) {
        $_SESSION['user'] = $user['name'] ? $user['name'] : $user['cpf'];
        header('Location: /home');
        exit;
      } else {
        $error = 'RA ou senha inválidos.';
      }
    } else {
      $error = 'Preencha todos os campos.';
    }
  } elseif ($idType === 'cpf' && isset($_POST['cpf'])) {
    $cpf = $_POST['cpf'];
    $password = isset($_POST['password']) ? $_POST['password'] : '';
    if (!empty($cpf) && !empty($password)) {
      $user = getUserByCPF($pdo, $cpf);
      if ($user && $user['password'] === $password) {
        $_SESSION['user'] = $user['name'] ? $user['name'] : $user['cpf'];
        header('Location: /home');
        exit;
      } else {
        $error = 'CPF ou senha inválidos.';
      }
    } else {
      $error = 'Preencha todos os campos.';
    }
  } else {
    $error = 'Selecione RA ou CPF.';
  }
}
