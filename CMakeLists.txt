cmake_minimum_required(VERSION 3.15)
project(hogar_inteligente CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

include_directories(include)
add_executable(hogar src/main.cpp src/DispositivoInteligente.cpp)
