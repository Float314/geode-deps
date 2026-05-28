cmake_minimum_required(VERSION 3.15)
project(geode-deps-mgr)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(
   DOWNLOAD
   https://github.com/cpm-cmake/CPM.cmake/releases/download/v0.42.3/CPM.cmake
   ${CMAKE_CURRENT_BINARY_DIR}/cmake/CPM.cmake
)
include(${CMAKE_CURRENT_BINARY_DIR}/cmake/CPM.cmake)

CPMAddPackage("gh:geode-sdk/json@3.3.0")

set(SOURCES
    src/main.cpp
    src/add/add.cpp
    src/argparse/argparse.cpp 
    src/delete/delete.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME}
    PRIVATE mat-json
)