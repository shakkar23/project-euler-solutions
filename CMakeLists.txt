
cmake_minimum_required(VERSION 3.22)

project(HelloWorld)

set(CMAKE_CXX_STANDARD 23)

add_executable(HelloWorld main.cpp)

# add -march=native to the compiler flags
if(LINUX)
    # assume that we use a compiler that supports the -march=native flag when on linux
    target_compile_options(HelloWorld PRIVATE -march=native)
endif()