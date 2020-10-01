cmake_minimum_required(VERSION 3.17)
project(SumReverseSortHeader)

set(CMAKE_CXX_STANDARD 17)

add_executable(SumReverseSortHeader main.cpp test_runner.h sum_reverse_sort.h sum_reverse_sort.cpp)