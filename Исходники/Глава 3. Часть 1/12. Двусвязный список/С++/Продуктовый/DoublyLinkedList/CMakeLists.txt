cmake_minimum_required(VERSION 3.25)
project(DoublyLinkedList)

set(CMAKE_CXX_STANDARD 23)

file(GLOB SOURCES "src/*.cpp")
add_executable(DoublyLinkedList ${SOURCES})


add_subdirectory(lib/googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

file(GLOB TEST_SOURCES "test/*.cpp")
add_executable(tests ${TEST_SOURCES})

target_link_libraries(tests gtest gtest_main)