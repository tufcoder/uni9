<!DOCTYPE html>
<html lang="pt-BR">

<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Projeto Integrado Uninove</title>
  <link rel="stylesheet" href="/css/style.css">
  <style>
    main.login-main {
      min-height: 100vh;
      display: flex;
      flex-direction: column;
      align-items: center;
      justify-content: center;
      gap: 1rem;
    }

    section.login-section {
      width: 100%;
      max-width: 350px;
      background: #fff;
      border-radius: 16px;
      box-shadow: 0 4px 24px rgba(0, 0, 0, 0.08);
      padding: 2rem 1.5rem;
      display: flex;
      flex-direction: column;
      align-items: center;
      gap: 1.5rem;
    }

    h1.title {
      font-weight: bold;
      font-size: 2.5rem;
      color: #222;
      margin-bottom: 0.5rem;
      letter-spacing: 0.05em;
    }

    form {
      display: flex;
      flex-direction: column;
      width: 100%;
      gap: 1rem;
    }

    form button {
      margin-top: 0.5rem;
      padding: 0.6rem 0;
      border: none;
      border-radius: 8px;
      background: #4f46e5;
      color: #fff;
      font-weight: bold;
      font-size: 1.1rem;
      cursor: pointer;
      transition: background 0.2s;
    }

    form button:hover {
      background: #3730a3;
    }

    .radio-wrapper {
      display: flex;
      align-items: center;
      justify-content: center;
      gap: 1rem;
      text-transform: uppercase;
      font-size: 1rem;
      color: #555;
    }

    .radio-wrapper input[type="radio"] {
      accent-color: #4f46e5;
    }

    .content-wrapper {
      display: flex;
      flex-direction: column;
      gap: 0.75rem;
    }

    .content-wrapper input[type="text"],
    .content-wrapper input[type="password"] {
      padding: 0.6rem;
      border: 1px solid #d1d5db;
      border-radius: 8px;
      font-size: 1rem;
      background: #f9fafb;
      transition: border 0.2s;
    }

    .content-wrapper input[type="text"]:focus,
    .content-wrapper input[type="password"]:focus {
      border-color: #4f46e5;
      outline: none;
    }

    .error-message {
      min-height: 1.5em;
      margin-bottom: 0.5em;
      color: #dc2626;
      display: flex;
      align-items: center;
      justify-content: center;
      font-size: 1rem;
    }

    .error-message p {
      margin: 0;
    }

    @media (max-width: 500px) {
      section.login-section {
        max-width: 95vw;
        padding: 1rem 0.5rem;
      }

      h1.title {
        font-size: 2rem;
      }
    }
  </style>
</head>

<body>
  <main class="login-main">
    <section class="login-section">
      <h1 class="title">Sign In</h1>
      <div class="error-message" role="alert">
        <?php if (isset($error)) {
          echo '<p>' . $error . '</p>';
        } ?>
      </div>
      <form method="POST">
        <div class="radio-wrapper">
          <label for="radio-ra">
            <input type="radio" name="id-type" id="radio-ra" value="ra" <?php echo (isset($_POST['id-type']) ? ($_POST['id-type'] === 'ra' ? 'checked' : '') : 'checked'); ?>>
            <span>ra</span>
          </label>
          <label for="radio-cpf">
            <input type="radio" name="id-type" id="radio-cpf" value="cpf" <?php echo (isset($_POST['id-type']) && $_POST['id-type'] === 'cpf' ? 'checked' : ''); ?>>
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
