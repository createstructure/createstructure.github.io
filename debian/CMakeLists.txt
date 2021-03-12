# for snap
cmake_minimum_required(VERSION 3.1)
find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})
target_link_libraries(Python.h ${PYTHON_LIBRARIES})

project(createstructure)

add_executable(createstructure createstructure.c)
install(TARGETS createstructure RUNTIME DESTINATION bin)
