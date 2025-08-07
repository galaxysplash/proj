cmake_minimum_required(VERSION 3.28)
project(MultiThreading)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCES *.cpp)
add_library(${PROJECT_NAME} ${SOURCES})