cmake_minimum_required(VERSION 3.27)
project(ExamSystem)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ExamSystem
        Classes.h
        main.cpp
        Utils.h)
