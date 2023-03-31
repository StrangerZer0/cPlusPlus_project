cmake_minimum_required(VERSION 3.20)
project(Projekt)

set(CMAKE_CXX_STANDARD 14)

set(PROJECT_HEADERS FileIOEngine.h Database.h FileHistory.cpp FileHistory.h)
set(PROJECT_SOURCES FileIOEngine.cpp Database.cpp FileHistory.cpp FileHistory.h)

add_executable(Projekt main.cpp ${PROJECT_SOURCES} ${PROJECT_HEADERS})
