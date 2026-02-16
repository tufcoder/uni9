create table if not exists users (
  id int not null primary key auto_increment,
  email varchar(100) not null unique,
  password varchar(100) not null,
  username varchar(100) null,
  created_at datetime not null default CURRENT_TIMESTAMP,
  updated_at datetime not null default CURRENT_TIMESTAMP on update CURRENT_TIMESTAMP
);

insert into users (email, password) values ('johndoe@email.com', '1234');

select * from users;
