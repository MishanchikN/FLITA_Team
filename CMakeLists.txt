cmake_minimum_required(VERSION 3.25)
project(FLITA_team C)

set(CMAKE_C_STANDARD 23)

add_executable(FLITA_team main.c shakersort.c main.h bead_sort.c additional_functions.c)
