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
        require_once __DIR__ . '/../src/login.php';
        // Exibe o formulário de login (código HTML original)
        ?>
        <!DOCTYPE html>
        <html lang="pt-BR">
        <head>
            <meta charset="UTF-8">
            <meta name="viewport" content="width=device-width, initial-scale=1.0">
            <title>Projeto Integrado Uninove</title>
            <style>
                html { box-sizing: border-box; }
                *, *::after, *::before { box-sizing: inherit; }
                * { margin: 0; font: inherit; }
                body { font: normal 1rem/1.4 Arial, sans-serif; }
                main.login-main { min-height: 100vh; display: flex; flex-direction: column; align-items: center; justify-content: center; gap: 1rem; }
                section.login-section { width: 100%; max-width: 200px; display: flex; flex-direction: column; align-items: center; gap: 1rem; }
                h1.title { font-weight: bold; font-size: 2.5rem; }
                form { display: flex; flex-direction: column; width: 100%; }
                form button { margin-top: 0.5rem; }
                .radio-wrapper { display: flex; align-items: center; justify-content: center; gap: 1rem; text-transform: uppercase; }
                .content-wrapper { display: flex; flex-direction: column; gap: 0.25rem; }
                .error-message { min-height: 1.5em; margin-bottom: 0.5em; color: red; display: flex; align-items: center; justify-content: center; }
                .error-message p { margin: 0; }
            </style>
        </head>
        <body>
            <main class="login-main">
                <section class="login-section">
                    <h1 class="title">Login</h1>
                    <div class="error-message" role="alert">
                        <?php if (isset($error)) { echo '<p>' . $error . '</p>'; } ?>
                    </div>
                    <form method="POST">
                        <div class="radio-wrapper">
                            <label for="radio-ra">
                                <input type="radio" name="id-type" id="radio-ra" value="ra" checked>
                                <span>ra</span>
                            </label>
                            <label for="radio-cpf">
                                <input type="radio" name="id-type" id="radio-cpf" value="cpf">
                                <span>cpf</span>
                            </label>
                        </div>
                        <div class="content-wrapper">
                            <input type="text" name="ra" id="input-id" placeholder="Digite seu RA">
                            <input type="password" name="password" id="password" placeholder="Digite sua senha">
                            <button type="submit">Entrar</button>
                        </div>
                    </form>
                </section>
            </main>
            <script>
                const radioRA = document.getElementById('radio-ra');
                const radioCPF = document.getElementById('radio-cpf');
                const inputId = document.getElementById('input-id');

                function updateInput() {
                    if (radioCPF.checked) {
                        inputId.placeholder = 'Digite seu CPF';
                        inputId.name = 'cpf';
                    } else {
                        inputId.placeholder = 'Digite seu RA';
                        inputId.name = 'ra';
                    }
                    inputId.value = '';
                    inputId.focus();
                }

                radioRA.addEventListener('change', updateInput);
                radioCPF.addEventListener('change', updateInput);
                window.addEventListener('DOMContentLoaded', updateInput);
            </script>
        </body>
        </html>
        <?php
        break;
    case '/home':
        require_once __DIR__ . '/pages/home.php';
        break;
    case '/logout':
        require_once __DIR__ . '/../src/logout.php';
        break;
    default:
        http_response_code(404);
        echo 'Página não encontrada';
        break;
}
