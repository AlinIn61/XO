cmake_minimum_required(VERSION 3.24)
project(XO)

set(CMAKE_CXX_STANDARD 17)

add_executable(XO main.cpp Draw.cpp Draw.h globals.h AiPC.cpp AiPC.h)

find_package(raylib CONFIG REQUIRED)
target_link_libraries(XO PRIVATE raylib)
