#!/bin/sh

# This script build raymui demo int a single header file way.

CC="gcc"
LIBS="-lraylib -lGL -lm -lpthread -ldl -lrt -lX11"
FLAGS="-std=c99 -Wall -Werror"
SRCS="./src/demo_single_header.c"
EXE="raymui_single_header_demo"

$CC $FLAGS $SRCS -o $EXE $LIBS
