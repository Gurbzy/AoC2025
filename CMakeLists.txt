cmake_minimum_required(VERSION 3.16)
project(aoc2025 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(AOC_SOURCES
    src/main.cpp
    src/days/day1.cpp
)

add_executable(aoc ${AOC_SOURCES})

target_include_directories(aoc PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

