cmake_minimum_required(VERSION 3.13)
project(Hw2)
add_executable(Hw2 main.cpp)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

include_directories( ${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})

target_link_libraries(Hw2 ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})