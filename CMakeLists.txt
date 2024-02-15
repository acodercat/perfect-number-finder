cmake_minimum_required(VERSION 3.20)
project(PerfectNumberFinder VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

enable_testing()

add_library(core_lib
        src/PerfectNumber.cpp
        src/NumberReader.cpp
        src/ThreadManager.cpp
)
target_include_directories(core_lib PUBLIC include)

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE core_lib)

option(BUILD_TESTS "Build the unit tests" OFF)
if(BUILD_TESTS AND EXISTS "${PROJECT_SOURCE_DIR}/tests")
    add_subdirectory(external/googletest)

    add_executable(Tests
            tests/NumberReaderTest.cpp
            tests/PerfectNumberTest.cpp
            tests/ThreadManagerTest.cpp
    )
    target_link_libraries(Tests gtest_main core_lib)
    target_include_directories(Tests PRIVATE external/googletest/googletest/include)

    include(GoogleTest)
    gtest_discover_tests(Tests)
endif()
