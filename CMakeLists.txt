cmake_minimum_required(VERSION 3.14)
project(Sorts)

set(CMAKE_CXX_STANDARD 17)

add_executable(Sorts main.cpp bubble.h counting.h insert.h merge.h mocker.cpp mocker.h quick.h radix.h select.h shell.h sort.h tester.cpp tester.h)