cmake_minimum_required(VERSION 3.6.2)
project(gravity)

include_directories(include)
file(GLOB SOURCES "src/*.cpp")
add_executable(gravity ${SOURCES})