cmake_minimum_required(VERSION 3.27)
project(bankbgd)

set(CMAKE_CXX_STANDARD 17)

add_executable(bankbgd main.cpp
        DataSourceInterface.cpp
        DataSourceInterface.h
        Parser.cpp
        Parser.h)
