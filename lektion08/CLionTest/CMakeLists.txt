cmake_minimum_required(VERSION 3.30)
project(ClionTest)

set(CMAKE_CXX_STANDARD 20)

add_executable(ClionTest main.cpp)


include_directories(CppTestLib)
add_subdirectory(CppTestLib)

target_link_libraries(ClionTest CppTestLib_lib)

add_subdirectory(GTest)
