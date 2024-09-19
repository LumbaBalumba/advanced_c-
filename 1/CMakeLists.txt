cmake_minimum_required(VERSION 3.26)
project(Hello LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_COMPILE_FEATURES "-Wall -Werror -fsanitize=leak -fsanitize=undefined -fsanitize=address -m64")

file(GLOB SOURCES "src/*.cpp")

include_directories(include)
add_executable(hello ${SOURCES})
