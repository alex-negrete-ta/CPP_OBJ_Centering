cmake_minimum_required(VERSION 3.10)

# Project Name
project(CPP_OBJ_Centering)

# C++ standard
set (CMAKE_CXX_STANDARD 17)

# Find the .h files.
include_directories(include)

# The program
add_executable(OBJCENTER
    src/main.cpp
    src/Mesh.cpp
)