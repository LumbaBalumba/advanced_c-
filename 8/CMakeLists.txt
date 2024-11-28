cmake_minimum_required(VERSION 3.26)
project(Hello LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)

add_executable(1 src/1.cpp)
add_executable(2 src/2.cpp)
add_executable(3 src/3.cpp)
add_executable(4 src/4.cpp)
add_executable(5 src/5.cpp)
add_executable(6 src/6.cpp)
add_executable(7 src/7.cpp)
add_executable(8 src/8.cpp)

find_package(Boost-1.86.0 COMPONENTS coro2)

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_NO_BOOST_CMAKE ON)
find_package(Boost COMPONENTS coro2)

find_package(
  Boost
  COMPONENTS fiber system filesystem
  REQUIRED)
if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
  target_link_libraries(1 ${Boost_LIBRARIES})
  target_link_libraries(2 ${Boost_LIBRARIES})
  target_link_libraries(3 ${Boost_LIBRARIES})
endif()
