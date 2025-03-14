cmake_minimum_required(VERSION 3.10)
project(part2)



# 모든 .c파일 자동감지
file(GLOB EXECUTABLES "${CMAKE_CURRENT_LIST_DIR}/*.c")   # <-List와 source구분

foreach(EXECUTABLE ${EXECUTABLES})
    get_filename_component(EXE_NAME ${EXECUTABLES} NAME_WE)
    add_executable(${EXE_NAME} ${EXECUTABLES})
endforeach()