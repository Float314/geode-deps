# lol its my first time writing a neeeat CMakeLists lol

# So, the basics :)
cmake_minimum_required(VERSION 3.15)
project(geode-deps
    VERSION 1.0.0
    LANGUAGES CXX
    PROJECT_HOMEPAGE_URL https://geode-sdk.org/
)

# C/C++ Standard (11/23 respectively)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Download CPM, cause this shit doesnt come bundled in 
message("-- Downloading CPM v0.42.3")
file(
   DOWNLOAD
   https://github.com/cpm-cmake/CPM.cmake/releases/download/v0.42.3/CPM.cmake
   ${CMAKE_CURRENT_BINARY_DIR}/cmake/CPM.cmake
)
include(${CMAKE_CURRENT_BINARY_DIR}/cmake/CPM.cmake)
message("-- CPM Successfully fetched!")
include(FetchContent)

message("-- Fetching Dependencies ")

set(CXX_HTTPLIB_LIBHDR "${CMAKE_CURRENT_BINARY_DIR}/third_party/httplib.h")

# Check if cpp-httplib is there
if(NOT EXISTS "${CXX_HTTPLIB_LIBHDR}")
    message("-- Downloading cpp-httplib")
    file(DOWNLOAD
        "https://raw.githubusercontent.com/yhirose/cpp-httplib/v0.46.0/httplib.h"
        "${CXX_HTTPLIB_LIBHDR}"
    )
    message("-- Downloaded cpp_httplib!")
else()
    message("-- cpp-httplib is already on the path ${CXX_HTTPLIB_LIBHDR}. Skipping Download")
endif()

CPMAddPackage("gh:geode-sdk/json@3.3.0")

set(SOURCES
    src/main.cpp
    src/add/add.cpp
    src/argparse/argparse.cpp 
    src/delete/delete.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

find_package(OpenSSL REQUIRED)
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_BINARY_DIR}/third_party")
target_link_libraries(${PROJECT_NAME} PRIVATE
    mat-json
    OpenSSL::SSL
    OpenSSL::Crypto
)