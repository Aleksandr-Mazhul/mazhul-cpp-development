cmake_minimum_required(VERSION 3.16)
project(pizza_project LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(pizza
        main.cpp
        Pizza.cpp
        Order.cpp
)


