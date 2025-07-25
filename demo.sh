#!/bin/sh

# This script build raymui demo in the most simple way.
# It uses :  
#   - microui.h
#   - raymui.h
#   - microui.c
#   - raymui.c

CC="gcc"
LIBS="-lraylib -lGL -lm -lpthread -ldl -lrt -lX11"
FLAGS="-std=c99 -Wall -Werror -I./src"
SRCS="./src/microui.c ./src/raymui.c ./src/demo.c"
EXE="raymui_demo"

$CC $FLAGS $SRCS -o $EXE $LIBS
