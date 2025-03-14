cmake_minimum_required(VERSION 3.10)
project(bookSql)

set(SOURECE 
src/main.c 
src/bookSql.c)

add_executable(bookSql ${SOURCES})
target_include_directories(bookSql PRIVATE include)

target_include_directories(bookSql PRIVATE /usr/include/mysql)
target_link_directories(bookSql PRIVATE /usr/lib/mysql)
target_link_libraries(bookSql PRIVATE mysqlclient)
