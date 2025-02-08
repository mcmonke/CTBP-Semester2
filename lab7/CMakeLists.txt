cmake_minimum_required(VERSION 3.2)

set(project "lab7")
project(${project})

    
set(CMAKE_CXX_STANDARD 17)

set(${project}_SOURCES
        main.cpp)

add_subdirectory(vectorx)
add_subdirectory(virtual)

set(${project}_SOURCE_LIST
        ${${project}_SOURCES})

add_executable(${project}
        ${${project}_SOURCE_LIST})

target_link_libraries(${project} vectorx)
target_link_libraries(${project} virtual)