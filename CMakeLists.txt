cmake_minimum_required(VERSION 3.14)
project(RT C)

find_library(SDL2 SDL2)
set(SOURCE_FILES tutorial.c)
add_executable(RT ${SOURCE_FILES})
target_link_libraries(RT ${SDL2})
