#!/bin/sh

set -xe

CFLAGS="-Wall -Wextra -ggdb `pkg-config --cflags raylib`"
LIBS="`pkg-config --libs raylib` -lm -ldl -lpthread"
DYNAMIC_LIBS="-L./build/ -lplugins"

#Build Directory
mkdir -p ./build/

#Plugins
clang $CFLAGS -o ./build/libplugins.so -fPIC -shared ./plugins/plugins.c $LIBS

#Main
clang $CFLAGS -o ./build/main main.c $LIBS $DYNAMIC_LIBS
