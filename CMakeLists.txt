cmake_minimum_required(VERSION 3.20)

project(Calc LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

add_executable(Calculator src/main.cpp src/File/File.h src/File/File.cpp src/Variables/Variables.cpp src/Variables/Variables.h src/Token/Token.cpp src/Token/Token.h src/RPN/RPN.cpp src/RPN/RPN.h src/isDebug/isDebug.h src/isDebug/isDebug.cpp src/Debug/Debug.cpp src/Debug/Debug.h src/Containers/Vector/Vector.cpp src/Containers/Vector/Vector.h src/Arguments/Arguments.cpp src/Arguments/Arguments.h)
