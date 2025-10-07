#!/bin/bash
set -e

# Compila todos los archivos .cpp del proyecto y enlaza con MySQL Connector/C++
# Busca recursivamente los .cpp (incluye Librerias/)

ALL_SRC=$(find . -name "*.cpp")


if [ -z "$ALL_SRC" ]; then
    echo "No se han encontrado archivos .cpp para compilar"
    exit 1
fi

PKG_FLAGS=$(pkg-config --cflags --libs gtkmm-3.0 2>/dev/null || echo "")

# Si gtkmm está disponible, compilamos todo; si no, excluimos la GUI
if [ -n "$PKG_FLAGS" ]; then
	# Excluir archivos que definen main distintos (como Pruebas.cpp) y usar gui_main.cpp
	SRC_FILES=$(echo "$ALL_SRC" | grep -v "./Pruebas.cpp" | grep -v "./testing" || true)
	echo "gtkmm detectado: compilando con GUI"
	g++ -std=c++17 -Wall -Wextra -I/usr/include/mysql -I. $SRC_FILES -L/usr/lib/x86_64-linux-gnu -lmysqlcppconn $PKG_FLAGS -o testing
else
	echo "pkg-config no encontró gtkmm-3.0. Compilando sin GUI (asegúrate de instalar libgtkmm-3.0-dev)."
	# Excluir archivos de la GUI para compilar solo la parte consola
	SRC_FILES=$(echo "$ALL_SRC" | grep -v "./Librerias/GUI" | grep -v "./gui_main.cpp" || true)
	g++ -std=c++17 -Wall -Wextra -I/usr/include/mysql -I. $SRC_FILES -L/usr/lib/x86_64-linux-gnu -lmysqlcppconn -o testing
fi

echo "Compilación finalizada: ./testing"
