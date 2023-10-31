cmake_minimum_required(VERSION 3.26)
project(Proyecto)

set(CMAKE_CXX_STANDARD 17)

add_executable(Proyecto main.cpp
        SLList.h
        DLList.h
        Stack.h
        Queue.h)
