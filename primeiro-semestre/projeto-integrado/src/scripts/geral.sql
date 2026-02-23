-- Criação do banco de dados, charset, collation e timezone
CREATE DATABASE IF NOT EXISTS uninove
	DEFAULT CHARACTER SET utf8mb4
	DEFAULT COLLATE utf8mb4_0900_ai_ci;

USE uninove;

SET time_zone = '+00:00';

CREATE TABLE IF NOT EXISTS roles (
	id int NOT NULL PRIMARY KEY auto_increment,
	role varchar(50) NOT NULL UNIQUE,
	created_at datetime not null default CURRENT_TIMESTAMP,
	updated_at datetime not null default CURRENT_TIMESTAMP on update CURRENT_TIMESTAMP
);

CREATE TABLE IF NOT EXISTS users (
	id int NOT NULL PRIMARY KEY auto_increment,
	cpf varchar(11) not null unique,
	password varchar(100) not null,
	name varchar(100) NULL,
	created_at datetime not null default CURRENT_TIMESTAMP,
	updated_at datetime not null default CURRENT_TIMESTAMP on update CURRENT_TIMESTAMP
);

CREATE TABLE IF NOT EXISTS user_roles (
	user_id int NOT NULL,
	role_id int NOT NULL,
	created_at datetime not null default CURRENT_TIMESTAMP,
	updated_at datetime not null default CURRENT_TIMESTAMP on update CURRENT_TIMESTAMP,
	PRIMARY KEY (user_id, role_id),
	FOREIGN KEY (user_id) REFERENCES users(id),
	FOREIGN KEY (role_id) REFERENCES roles(id)
);


CREATE TABLE IF NOT EXISTS students (
	user_id int NOT NULL,
	ra varchar(15) NOT NULL UNIQUE,
	created_at datetime not null default CURRENT_TIMESTAMP,
	updated_at datetime not null default CURRENT_TIMESTAMP on update CURRENT_TIMESTAMP,
	PRIMARY KEY (user_id, ra),
	FOREIGN KEY (user_id) REFERENCES users(id)
);

CREATE TABLE IF NOT EXISTS login_attempts (
    id INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
    user_id INT NULL,
    user_identifier VARCHAR(50) NOT NULL,
    ip_address VARCHAR(45) NOT NULL,
    attempt_time DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    success BOOLEAN NOT NULL,
    resolved BOOLEAN NOT NULL DEFAULT 0,
    FOREIGN KEY (user_id) REFERENCES users(id)
);

INSERT INTO roles (role) values ('Admin');
INSERT INTO roles (role) values ('Aluno');
INSERT INTO roles (role) values ('Coordenador');
INSERT INTO roles (role) values ('Professor');

INSERT INTO users (cpf, password) values ('12345678909', '1234');
INSERT INTO users (cpf, password, name) values ('09876543211', '1234', 'John Doe');
INSERT INTO users (cpf, password) values ('23456789010', '1234');
INSERT INTO users (cpf, password) values ('34567890122', '1234');

INSERT INTO user_roles (user_id, role_id) values (1, 1);
INSERT INTO user_roles (user_id, role_id) values (2, 2);
INSERT INTO user_roles (user_id, role_id) values (3, 3);
INSERT INTO user_roles (user_id, role_id) values (4, 4);
INSERT INTO user_roles (user_id, role_id) values (4, 3);

INSERT INTO students (user_id, ra) values (2, '1234567890');

/*
UPDATE users SET password = '$2y$10$d07nO5cp53i2aRz6tyR9vOicwh/6NE8rJGEKV9lMirgpuRurC7Ini' WHERE cpf = '12345678909';
UPDATE users SET password = '$2y$10$XXopHe3GnNlu4xbeabFOcuq4V9FO1b/mxBk1fJprjaJcgj.s8oph2' WHERE cpf = '09876543211';
UPDATE users SET password = '$2y$10$t63g1WJ0378k2GaCu93WT.8G3FYEvAuhZg6zceI22uJLOS2/7EIeK' WHERE cpf = '23456789010';
UPDATE users SET password = '$2y$10$YNV9t.nWxiAHD3HIuPxcY.Vk5rqC7NHbi3owd3nRBX5CGImV8yI66' WHERE cpf = '34567890122';
*/

-- query para trazer todos os users que são students
SELECT
	r.role
	,s.ra
	,u.*
FROM users u
	INNER JOIN user_roles ur ON u.id = ur.user_id
	INNER JOIN roles r ON ur.role_id = r.id
	INNER JOIN  students s ON u.id = s.user_id
;
