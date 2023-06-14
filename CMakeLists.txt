cmake_minimum_required(VERSION 3.10)
project(CeSSL C)

set(CMAKE_C_FLAGS "--std=gnu99")

add_executable(CeSSL main.c)


include_directories(./include/cessl)
include_directories(./src )
link_directories(./libs)


file(GLOB_RECURSE HEADERS    RELATIVE ${CMAKE_SOURCE_DIR} "header/*/*.h")
file(GLOB_RECURSE SOURCECODE RELATIVE ${CMAKE_SOURCE_DIR} "src/*.c")

link_libraries(pthread)
link_libraries(dl)
link_libraries(m)

#add_library(Ce_SSL_dynamic  ${HEADERS}  ${SOURCECODE} )
#set_target_properties(Ce_SSL_dynamic PROPERTIES CLEAN_DIRECT_OUTPUT 1)

add_definitions("-lm")

add_executable(ssltest main.c ${HEADERS} ${SOURCECODE})