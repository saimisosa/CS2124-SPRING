cmake_minimum_required(VERSION 3.15)
project(rec07_sepComp)

set(CMAKE_CXX_STANDARD 14)

add_executable(rec07_sepComp main.cpp Student.cpp Student.h Registrar.cpp Registrar.h Course.cpp Course.h)