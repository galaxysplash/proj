cmake_minimum_required(VERSION 3.28)

set(CMAKE_TOOLCHAIN_FILE /home/marcel/extern/vcpkg/scripts/buildsystems/vcpkg.cmake)

project(proj_gen)

include_directories(include)

add_subdirectory(lib)

