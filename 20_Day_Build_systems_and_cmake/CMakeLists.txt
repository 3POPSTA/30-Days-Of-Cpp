cmake_minimum_required(VERSION 3.20)
project(Day20_BuildDemo VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(cmake_demo main.cpp)

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(cmake_demo PRIVATE -Wall -Wextra -Wpedantic)
elseif (MSVC)
    target_compile_options(cmake_demo PRIVATE /W4)
endif()
