cmake_minimum_required(VERSION 3.9)
project(HomemadeBitset)

set(CMAKE_CXX_STANDARD 14)

add_library(catch test/catch_main.cpp)

add_executable(test_task test/test_task.cpp Bitset.cpp)
target_link_libraries(test_task catch)
