cmake_minimum_required(VERSION 3.20)
project(PerfectNumberFinder VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SRC_FILES
    src/main.cpp
    src/PerfectNumber.cpp
    src/NumberReader.cpp
    src/ThreadManager.cpp
)

add_executable(${PROJECT_NAME} ${SRC_FILES})
target_include_directories(${PROJECT_NAME} PRIVATE include)

option(BUILD_TESTS "Build the unit tests" OFF)
if(BUILD_TESTS AND EXISTS "${PROJECT_SOURCE_DIR}/tests")
    add_subdirectory(external/googletest)

    add_executable(Tests
        tests/NumberReaderTest.cpp
        tests/PerfectNumberTest.cpp
        tests/ThreadManagerTest.cpp
        src/PerfectNumber.cpp
        src/NumberReader.cpp
        src/ThreadManager.cpp
    )
    target_link_libraries(Tests gtest gtest_main)

    target_include_directories(Tests PRIVATE ${PROJECT_SOURCE_DIR}/include)
    target_include_directories(Tests PRIVATE external/googletest/googletest/include)

    enable_testing()
    include(GoogleTest)

    gtest_discover_tests(Tests)
endif()