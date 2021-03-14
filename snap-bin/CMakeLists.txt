# By Castellani Davide
cmake_minimum_required(VERSION 3.1)
project(createstructure)

add_definitions("-DCMAKE_C_COMPILER=/usr/bin/gcc")

add_executable(createstructure createstructure.c)
install(TARGETS createstructure RUNTIME DESTINATION bin)
