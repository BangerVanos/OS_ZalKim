cmake_minimum_required(VERSION 3.20)
project(MeMager C)

set(CMAKE_C_STANDARD 11)

add_executable(MeMager main.c memager.c memager.h memager_tester.c memager_tester.h benchmark.c benchmark.h)
