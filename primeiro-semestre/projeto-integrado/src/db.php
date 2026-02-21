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
