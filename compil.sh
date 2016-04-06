#!/bin/bash
# Compile main.c to mlx program using Minilibx
gcc -o mlx main.c -lmlx -framework OpenGL -framework AppKit
