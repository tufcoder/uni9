<?php


if (session_status() !== PHP_SESSION_ACTIVE) {
  session_start();
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
