cmake_minimum_required(VERSION 3.14)

project(how-to-run-googletest)

# -fprofile-arcs -ftest-coverage for lcov
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -pthread")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -pthread -fprofile-arcs -ftest-coverage")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)
add_subdirectory(test)