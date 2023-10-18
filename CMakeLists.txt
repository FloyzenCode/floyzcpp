cmake_minimum_required(VERSION 3.20)

project(floyzcpp_project)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
message("Set CMAKE_CXX_STANDARD 17")
include_directories("${CMAKE_SOURCE_DIR}/src")
file(GLOB_RECURSE SOURCE_FILES "${CMAKE_SOURCE_DIR}/src/*.cpp" "main.cpp")
message("Build...")
add_executable(floyzcpp ${SOURCE_FILES})