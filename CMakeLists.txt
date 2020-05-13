cmake_minimum_required(VERSION 3.10)

project(PROJECTNAME)

enable_language(CXX)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

enable_testing()
option(BUILD_TESTING "Build tests" ON)

add_subdirectory(external)
add_subdirectory(src)
