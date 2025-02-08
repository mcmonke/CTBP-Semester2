cmake_minimum_required(VERSION 3.28)

set(project lab8)

project(${project})

set(CMAKE_CXX_STANDARD 20)

set(${project}_SOURCES main.cpp)

set(${project}_SOURCE_LIST ${${project}_SOURCES})

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/build/input.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
        
add_executable(${project} ${${project}_SOURCE_LIST}) 