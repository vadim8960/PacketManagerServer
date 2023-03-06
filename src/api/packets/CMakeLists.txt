cmake_minimum_required(VERSION 3.23)
project(packets_api)

set(CMAKE_CXX_STANDARD 17)

add_library(${PROJECT_NAME} STATIC packets_api.cpp packets_api.h)

target_link_libraries(${PROJECT_NAME} PUBLIC drogon)
target_link_libraries(${PROJECT_NAME} PUBLIC sqlreader)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})