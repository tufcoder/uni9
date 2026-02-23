<?php


if (session_status() !== PHP_SESSION_ACTIVE) {
  session_start();
  // Expiração de sessão por inatividade (15 minutos)
  if (isset($_SESSION['user'])) {
    $timeout = 900; // segundos
    if (!isset($_SESSION['last_activity'])) {
      $_SESSION['last_activity'] = time();
    } elseif (time() - $_SESSION['last_activity'] > $timeout) {
      session_unset();
      session_destroy();
      header('Location: /index.php?timeout=1');
      exit;
    }
    $_SESSION['last_activity'] = time();
  }
  // Geração de token CSRF
  if (!isset($_SESSION['csrf_token'])) {
    $_SESSION['csrf_token'] = bin2hex(random_bytes(32));
  }
}

$uri = parse_url($_SERVER['REQUEST_URI'], PHP_URL_PATH);

switch ($uri) {
  case '/':
  case '/index.php':
    // Se já está logado, vai para a home
    if (isset($_SESSION['user'])) {
      header('Location: /home');
      exit;
    }
    // Se não está logado, processa o login
    require_once __DIR__ . '/src/login.php';
    // Exibe o formulário de login
    require_once __DIR__ . '/pages/sign-in.php';
    break;
  case '/home':
    require_once __DIR__ . '/pages/home.php';
    break;
  case '/logout':
    require_once __DIR__ . '/src/logout.php';
    break;
  default:
    http_response_code(404);
    echo 'Página não encontrada';
    break;
}
