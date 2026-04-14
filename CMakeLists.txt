cmake_minimum_required(VERSION 3.16)
project(mazhul_cpp_development LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Independent projects are connected as separate subdirectories.
add_subdirectory(cpp-semester-2/09-10-04-2026/pizza)
