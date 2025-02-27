
project(GTest)

add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(GTest_run test.cpp)

target_link_libraries(GTest_run CppTestLib_lib)
target_link_libraries(GTest_run gtest_main)

