<!DOCTYPE html>
<html lang="pt-BR">
  <head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Projeto Integrado Uninove</title>
    <style>
      html {
        box-sizing: border-box;
      }

      *, *::after, *::before {
        box-sizing: inherit;
      }

      * {
        margin: 0;
        font: inherit;
      }

      body {
        font: normal 1rem/1.4 Arial, sans-serif;
      }

      .login-wrapper {
        /* width: 50rem;
        margin: 0 auto; */
        min-height: 100vh;
        display: flex;
        flex-direction: column;
        align-items: center;
        justify-content: center;
        gap: 1rem;
        /* display: grid;
        place-items: center;
        min-height: 100vh; */
      }

      .title {
        font-weight: bold;
        font-size: 2.5rem;
      }

      form {
        display: flex;
        flex-direction: column;
      }

      form button {
        margin-top: 0.5rem;
      }

      .radio-wrapper {
        display: flex;
        align-items: center;
        justify-content: center;
        gap: 1rem;
        text-transform: uppercase;
      }

      .content-wrapper {
        display: flex;
        flex-direction: column;
        gap: 0.25rem;
      }
    </style>
  </head>
  <body>
    <div class="login-wrapper">
      <h1 class="title">Login</h1>
      <form method="POST">
          <div class="radio-wrapper">
            <label for="radio-ra">
              <input type="radio" name="id-type" id="radio-ra" checked>
              <span>ra</span>
            </label>
            <label for="radio-cpf">
              <input type="radio" name="id-type" id="radio-cpf">
              <span>cpf</span>
            </label>
          </div>
          <div class="content-wrapper">
            <input type="text" name="input-id" id="input-id" placeholder="Digite seu RA">
            <input type="password" name="password" id="password" placeholder="Digite sua senha">
            <button type="submit">Entrar</button>
          </div>
      </form>
    </div>
    <script>
      const radioRA = document.getElementById('radio-ra')
      const radioCPF = document.getElementById('radio-cpf')
      const inputId = document.getElementById('input-id')

      window.addEventListener('DOMContentLoaded', function() {
        if (radioCPF.checked) {
          inputId.placeholder = 'Digite seu CPF'
          inputId.name = 'cpf'
        } else {
          inputId.placeholder = 'Digite seu RA'
          inputId.name = 'ra'
        }
      })

      radioRA.addEventListener('change', function() {
        if (radioRA.checked) {
          inputId.placeholder = 'Digite seu RA'
          inputId.name = 'ra'
          inputId.id = 'input-id'
          inputId.value = ''
          inputId.focus()
        }
      })

      radioCPF.addEventListener('change', function() {
        if (radioCPF.checked) {
          inputId.placeholder = 'Digite seu CPF'
          inputId.name = 'cpf'
          inputId.id = 'input-id'
          inputId.value = ''
          inputId.focus()
        }
      })
    </script>
  </body>
</html>
