cmake_minimum_required(VERSION 3.20)
project(src)

set(CMAKE_CXX_STANDARD 20)

add_executable(src main.cpp File/File.h File/File.cpp Variables/Variables.cpp Variables/Variables.h Token/Token.cpp Token/Token.h RPN/RPN.cpp RPN/RPN.h)
