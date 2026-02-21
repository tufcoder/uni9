#!/bin/bash

# Script para preparar a pasta _dist para publicação
set -e

DIST="_dist"

# Remove tudo de _dist menos o .env

if [ -d "$DIST" ]; then
  find "$DIST" -mindepth 1 -not -name ".env" -exec rm -rf {} +
  CREATED=0
else
  mkdir "$DIST"
  CREATED=1
fi

# Copia arquivos e pastas essenciais
cp index.php "$DIST/"
cp -r pages "$DIST/"
cp -r css "$DIST/"
cp -r src "$DIST/"
cp -r vendor "$DIST/"
cp composer.json "$DIST/"
cp composer.lock "$DIST/"

# Se .env não existe, copia o .env-example e avisa para editar
if [ ! -f "$DIST/.env" ]; then
  if [ -f .env-example ]; then
    cp .env-example "$DIST/.env"
    if [ "$CREATED" -eq 1 ]; then
      echo "Pasta _dist criada com sucesso! Edite o arquivo .env antes de publicar."
    fi
  else
    if [ "$CREATED" -eq 1 ]; then
      echo "Pasta _dist criada, mas .env-example não encontrado. Crie o arquivo .env manualmente."
    fi
  fi

else
  if [ "$CREATED" -eq 1 ]; then
    echo "Pasta _dist criada com sucesso! O arquivo .env foi mantido."
  fi
fi

# Mensagem final
echo "Script de build executado com sucesso."
