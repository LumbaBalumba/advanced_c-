cmake_minimum_required(VERSION 3.15)
project(proj CXX)

set(CMAKE_CXX_STANDARD 23)

find_package(fmt REQUIRED)
find_package(Boost REQUIRED)

add_executable(proj src/proj.cpp src/main.cpp)
target_link_libraries(proj fmt::fmt Boost::boost)

install(TARGETS proj DESTINATION "."
        RUNTIME DESTINATION bin
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        )
