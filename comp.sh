#!/bin/bash
set -e

# Compila todos los archivos .cpp del proyecto y enlaza con MySQL Connector/C++
# Busca recursivamente los .cpp (incluye Librerias/)
SRC_FILES=$(find . -name "*.cpp")

if [ -z "$SRC_FILES" ]; then
	echo "No se han encontrado archivos .cpp para compilar"
	exit 1
fi

g++ -std=c++17 -Wall -Wextra -I/usr/include/mysql -I. $SRC_FILES -L/usr/lib/x86_64-linux-gnu -lmysqlcppconn -o testing
echo "Compilación finalizada: ./testing"
