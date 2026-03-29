cmake_minimum_required(VERSION 3.20)
project(Day29_TaskManager VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(task_cli main.cpp task.cpp task_manager.cpp)

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(task_cli PRIVATE -Wall -Wextra -Wpedantic)
elseif (MSVC)
    target_compile_options(task_cli PRIVATE /W4)
endif()
