cmake_minimum_required(VERSION 3.20)
project(PerfectNumberFinder VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

file(GLOB SRC_FILES "src/*.cpp")

add_executable(${PROJECT_NAME} ${SRC_FILES})
