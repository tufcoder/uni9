# Projeto Integrado Uninove

Este é um sistema web desenvolvido em PHP para o Projeto Integrado do curso ADS da Uninove.

**Tecnologias utilizadas:**
- PHP 8.1
- Nginx 1.25
- MySQL 8
- Docker e Docker Compose
- Composer (gerenciador de dependências PHP)

O projeto utiliza Docker para ambiente de desenvolvimento, com containers separados para aplicação PHP, servidor web Nginx e banco de dados MySQL. O código segue boas práticas de organização e facilita o deploy em ambientes de produção compartilhados (como Byethost).

## Principais funcionalidades
- Login por RA ou CPF
- Controle de sessão de usuário
- Separação de responsabilidades no código (MVC simplificado)

## Estrutura
- `index.php` — arquivo principal do sistema
- `pages/` — páginas acessíveis pelo navegador
- `css/` — estilos globais compartilhados
- `src/` — scripts PHP de backend (conexão, autenticação, etc)
- `vendor/` — dependências gerenciadas pelo Composer

## Como rodar
1. Configure o arquivo `.env` com os dados do banco e ambiente.
2. Suba os containers com Docker Compose:
   ```bash
   docker-compose up -d
   ```
3. Crie o banco e as tabelas executando o script SQL manualmente dentro do container do banco:
   ```bash
   docker exec -it <nome-ou-id-do-container-db> bash
   # Dentro do container (a senha padrão é: root): 
   mysql -u root -p
   # No prompt do MySQL:
   source /var/www/html/src/scripts/geral.sql;
   ```
4. Acesse `http://localhost:8080` no navegador (index.php na raiz).


## Publicação em produção

Para facilitar o deploy, utilize o script de build automático:

```bash
./build_dist.sh
```

Esse script prepara a pasta `_dist` com todos os arquivos necessários para publicação:

- `index.php`
- `pages/`
- `css/`
- `src/`
- `vendor/`
- `.env` (mantém o arquivo existente ou copia o `.env-example` caso não exista)
- `composer.json` e `composer.lock`

O arquivo `.env-example` serve como modelo de configuração. Antes de publicar, edite o `.env` na pasta `_dist` com os dados do banco de dados e ambiente de produção:

```
DB_HOST=host_do_banco
DB_NAME=nome_do_banco
DB_USER=usuario_do_banco
DB_PASS=senha_do_banco
APP_ENV=production
```

Depois compacte a pasta `_dist` e faça o upload para o servidor, extraindo os arquivos na pasta pública (ex: htdocs). Assim, qualquer pessoa pode preparar o projeto para publicação de forma organizada e segura.

## Hospedagem

O projeto está disponível em produção no endereço:
https://uni9proj.web1337.net/


Agradecimento especial à [Byethost](https://byet.host/) pela hospedagem gratuita.

## Sobre o arquivo .htaccess (Byethost)

Para garantir o funcionamento correto do sistema em ambiente de hospedagem compartilhada (como a Byethost), utilizamos um arquivo `.htaccess` com as seguintes configurações:

```apache
php_value display_errors Off
php_value mbstring.http_input auto
php_value date.timezone America/Sao_Paulo

RewriteEngine On
RewriteCond %{HTTPS} off
RewriteRule ^ https://%{HTTP_HOST}%{REQUEST_URI} [L,R=301]

# Roteamento para index.php
RewriteCond %{REQUEST_FILENAME} !-f
RewriteCond %{REQUEST_FILENAME} !-d
RewriteRule ^ index.php [QSA,L]
```

**Explicação das diretivas:**

- `php_value display_errors Off`: Desativa a exibição de erros PHP em produção, aumentando a segurança.
- `php_value mbstring.http_input auto`: Garante o correto tratamento de caracteres multibyte em entradas HTTP.
- `php_value date.timezone America/Sao_Paulo`: Define o fuso horário padrão para o PHP.
- `RewriteEngine On` e regras de HTTPS: Forçam o acesso via HTTPS, redirecionando automaticamente requisições HTTP para HTTPS.
- As regras de roteamento (`RewriteCond` e `RewriteRule`) garantem que todas as URLs que não correspondem a arquivos ou pastas reais sejam redirecionadas para o `index.php`. Isso permite implementar rotas amigáveis e centralizar o controle das requisições, como em frameworks modernos.

Essas configurações são essenciais para garantir segurança, compatibilidade e funcionamento correto do sistema em servidores compartilhados.

---

> Projeto acadêmico — Uninove, 2026
