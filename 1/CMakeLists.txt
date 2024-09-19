cmake_minimum_required(VERSION 3.26)
project(Hello)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_COMPILE_FEATURES "-Wall -Werror -fsanitize=leak -fsanitize=undefined -fsanitize=address -m64")

include_directories(include)
add_executable(hello src/main.cpp src/hello.cpp)
