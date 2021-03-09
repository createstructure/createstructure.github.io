# for snap
cmake_minimum_required(VERSION 2.6)
project(createstructure)
add_executable(createstructure createstructure.c)
install(TARGETS createstructure RUNTIME DESTINATION bin)
