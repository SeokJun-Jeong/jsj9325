cmake_minimum_required(VERSION 3.10)
project(date)

#include_directories((${CMAKE_CURRENT_LIST_DIR}/include))   필요한 폴더가 있을때 
set(SOURECE 
main.c 
serial.c)

include_directories(${CMAKE_CURRENT_LIST_DIR})
add_executable(date ${SOURCES})

