# Projeto Integrado Uninove

Este é um sistema web desenvolvido em PHP para o Projeto Integrado do curso da Uninove. O projeto utiliza Docker para ambiente de desenvolvimento, MySQL como banco de dados e segue boas práticas de organização de código.

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
   # Dentro do container:
   mysql -u root -p
   # No prompt do MySQL:
   source /var/www/html/src/scripts/geral.sql;
   ```
   (A senha padrão é `root`)
4. Acesse `http://localhost:8080` no navegador (index.php na raiz).

---

> Projeto acadêmico — Uninove, 2026
