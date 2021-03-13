# for snap
cmake_minimum_required(VERSION 3.1)
project(createstructure)
CPLUS_INCLUDE_PATH=/usr/include/python3.8
export CPLUS_INCLUDE_PATH

add_executable(createstructure createstructure.c)
install(TARGETS createstructure RUNTIME DESTINATION bin)
