cmake_minimum_required(VERSION 3.23)
project(PacketManagerServer)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(libs)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC drogon)