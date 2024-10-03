cmake_minimum_required(VERSION 3.26)
project(Hello LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)

file(GLOB SOURCES src/*.cpp)

add_executable(hello ${SOURCES})
target_include_directories(hello PRIVATE include)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(hello PRIVATE -Wall -Wextra -Werror -fsanitize=leak,undefined,address)
    target_link_options(hello PRIVATE -fsanitize=leak,undefined,address)
endif()
