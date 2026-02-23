<?php
$senhas = [
  '12345678909' => '1234',
  '09876543211' => '1234',
  '23456789010' => '1234',
  '34567890122' => '1234'
];

foreach ($senhas as $cpf => $senha) {
  $hash = password_hash($senha, PASSWORD_DEFAULT);
  echo "UPDATE users SET password = '{$hash}' WHERE cpf = '{$cpf}';\n";
}
