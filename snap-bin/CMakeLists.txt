# By Castellani Davide
cmake_minimum_required(VERSION 3.1)
project(createstructure)

add_definitions("-DCMAKE_C_COMPILER=/usr/bin/gcc")
add_definitions("-std=c99 -ggdb3 -O0 -pedantic-errors -Wall -Wextra -fpie $(python3-config --cflags --embed) -o 'createstructure.out' 'createstructure.c' $(python3-config --embed --ldflags) && ./createstructure.out")

add_executable(createstructure createstructure.c)
install(TARGETS createstructure RUNTIME DESTINATION bin)
