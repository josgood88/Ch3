cmake_minimum_required(VERSION 3.0.0)
project(Ch3 VERSION 0.1.0)

include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD 17)              # C++17
set(CMAKE_CXX_STANDARD_REQUIRED True)   # Don't allow compiler to fall back to most recent version it knows
set(CMAKE_CXX_EXTENSIONS OFF)           # -std=c++11 rather than -std=gnu++11

include_directories(../include)
file (GLOB SOURCES src/*.cpp)   # file(GLOB...) allows for wildcard additions:
add_executable(Ch3 ${SOURCES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
