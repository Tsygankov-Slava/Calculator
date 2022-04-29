cmake_minimum_required(VERSION 3.20)

project(Calc LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

add_executable(Calc src/main.cpp src/File/File.h src/File/File.cpp src/Variables/Variables.cpp src/Variables/Variables.h src/Token/Token.cpp src/Token/Token.h src/RPN/RPN.cpp src/RPN/RPN.h src/isDebug/isDebug.h src/isDebug/isDebug.cpp src/Debug/Debug.cpp src/Debug/Debug.h src/Containers/Vector/Vector.cpp src/Containers/Vector/Vector.h src/Containers/Stack/Stack.cpp src/Containers/Stack/Stack.h src/Containers/Map/Map.cpp src/Containers/Map/Map.h src/Containers/Set/Set.cpp src/Containers/Set/Set.h)
