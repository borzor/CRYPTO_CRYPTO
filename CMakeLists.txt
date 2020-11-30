cmake_minimum_required(VERSION 3.5)

project(untilted)

add_executable(untilted main.c duck.h)
INCLUDE_DIRECTORIES("/home/boris/libakrypt-0.x/source")
target_link_libraries(untilted "/home/boris/build/libakrypt.so")
