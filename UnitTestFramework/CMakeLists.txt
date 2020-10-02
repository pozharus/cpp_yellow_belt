cmake_minimum_required(VERSION 3.16)
project(UnitTestFramework)

set(CMAKE_CXX_STANDARD 17)

add_executable(UnitTestFramework main.cpp test_framework.h)