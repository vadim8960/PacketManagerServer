cmake_minimum_required(VERSION 3.23)
project(sqlreader)

set(CMAKE_CXX_STANDARD 17)

add_library(${PROJECT_NAME} STATIC SqlReader.cpp SqlReader.h)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})