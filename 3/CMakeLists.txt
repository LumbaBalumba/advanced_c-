cmake_minimum_required(VERSION 3.26)
project(Hello LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)

file(GLOB SOURCES src/*.cpp)

add_executable(hello ${SOURCES})
target_include_directories(hello PRIVATE include)
