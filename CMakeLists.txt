cmake_minimum_required(VERSION 3.7)
project(as01)

set(CMAKE_C_STANDARD 11)

set(CMAKE_CXX_FLAGS "#{CMAKE_CXX_FLAGS} -Wall -Werror")
set(SOURCE_FILES main.c LIST.h LIST.c)
add_executable(as01 ${SOURCE_FILES} LIST.h LIST.c)