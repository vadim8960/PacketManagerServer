cmake_minimum_required(VERSION 3.23)
project(webapp)

set(CMAKE_CXX_STANDARD 17)

add_library(${PROJECT_NAME} STATIC App.cpp App.h)

target_link_libraries(${PROJECT_NAME} PUBLIC drogon)
target_link_libraries(${PROJECT_NAME} PUBLIC packets_api)

target_link_libraries(${PROJECT_NAME} PRIVATE sqlreader)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})