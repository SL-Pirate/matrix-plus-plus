cmake_minimum_required(VERSION 4.0)
project(matrix++)

find_package(Curses REQUIRED)

file(GLOB_RECURSE sources src/*.cpp)
add_executable(matrix++ ${sources})

target_include_directories(matrix++ PRIVATE include)

target_link_libraries(matrix++ PUBLIC
    Curses::Curses
)
