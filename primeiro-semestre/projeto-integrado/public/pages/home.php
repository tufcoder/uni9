<?php
	session_start();
	if (!isset($_SESSION['user'])) {
		header('Location: /index.php');
		exit;
	}
	$user = htmlspecialchars($_SESSION['user']);
?>
<!DOCTYPE html>
<html lang="pt-BR">
	<head>
		<meta charset="UTF-8">
		<title>Home</title>
		<style>

		body {
			background: #f5f5f5;
		}
		.center-container {
			min-height: 100vh;
			display: grid;
			place-items: center;
		}

    .header {
      width: 100%;
      display: flex;
      align-items: center;
      justify-content: space-between;
      padding: 1rem 2rem;
      background: #fff;
      box-shadow: 0 2px 8px rgba(0,0,0,0.04);
      margin-bottom: 2rem;
      box-sizing: border-box;
    }

    .header-title {
      font-size: 1.5rem;
      font-weight: bold;
      color: #1a237e;
      letter-spacing: 1px;
    }

    .logout-btn {
      background: #e53935;
      color: #fff;
      border: none;
      border-radius: 4px;
      padding: 0.5rem 1.2rem;
      font-size: 1rem;
      cursor: pointer;
      font-weight: bold;
      transition: background 0.2s;
    }

    .logout-btn:hover {
      background: #b71c1c;
    }

		.home-wrapper {
			background: #fff;
			padding: 2rem 3rem;
			border-radius: 8px;
			box-shadow: 0 2px 8px rgba(0,0,0,0.1);
		}
		</style>
	</head>
	<body>
	<div class="header">
		<span class="header-title">Uninove</span>
		<form method="post" action="/src/logout.php" style="margin:0;">
			<button type="submit" class="logout-btn">Deslogar</button>
		</form>
	</div>
	<div class="center-container">
		<div class="home-wrapper">
			<h1>Olá, <?php echo $user; ?>!</h1>
		</div>
	</div>
	</body>
</html>
