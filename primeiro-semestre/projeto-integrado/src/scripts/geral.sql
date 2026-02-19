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

SELECT
	r.role
	,u.*
FROM users u
	INNER JOIN user_roles ur ON u.id = ur.user_id
	INNER JOIN roles r ON ur.role_id = r.id
	;