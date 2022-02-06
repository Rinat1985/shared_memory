cmake_minimum_required(VERSION 3.16)
project(shared_memory)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

SET(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} "C:/Program Files/boost")

find_package(Boost 1.68.0 REQUIRED)


include_directories(${Boost_INCLUDE_DIRS})
include_directories(include)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")

add_subdirectory(src)

