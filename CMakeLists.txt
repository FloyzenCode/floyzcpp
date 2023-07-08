# build main.cpp
# Very good if you run code MSVC compiler
cmake_minimum_required(VERSION 3.12)

project(find_filesystem_win_gcc)

add_executable(curl_server main.cpp)

set_target_properties(
        curl_server PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED ON   
)

# Run & Build this project:
#   mkdir build
#   cd build
#   cmake ..