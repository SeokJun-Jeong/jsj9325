cmake_minimum_required(VERSION 3.10)
project(part1)

# set(CMAKE_C_COMPILER "/usr/bin/gcc")

# set(CMAKE_C_STANDARD 99)
# set(CMAKE_C_STANDARD_REQUIRED ON)

# set(EXECUTABLES
# c_example/part1/infinit.c  
# c_example/part1/arithmetics.c 
# c_example/part1/celsius.c 
# c_example/part1/charnumber.c 
# c_example/part1/compare.c 
# c_example/part1/compare2.c 
# c_example/part1/fourbit.c 
# c_example/part1/fourbit2.c 
# c_example/part1/free.c 
# c_example/part1/gender.c 
# c_example/part1/increase.c  
# c_example/part1/infinit.c 
# c_example/part1/limit.c  
# c_example/part1/literal.c  
# c_example/part1/oddeven.c 
# c_example/part1/sizeof.c 
# c_example/part1/test.c  
# c_example/part1/triangle.c  
# c_example/part1/triangle2.c
# )
file(GLOB EXECUTABLES "${CMAKE_CURRENT_LIST_DIR}/*.c")

foreach(EXECUTABLE ${EXECUTABLES})
    get_filename_component(EXE_NAME ${EXECUTABLES} NAME_WE)
    add_executable(${EXE_NAME} ${EXECUTABLES})
endforeach()