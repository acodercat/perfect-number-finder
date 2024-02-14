# Add library target
add_library(PerfectNumber ./PerfectNumber/PerfectNumber.cpp)


target_include_directories(PerfectNumber PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/PerfectNumber")

add_executable(PerfectNumberFinder main.cpp)

target_link_libraries(PerfectNumberFinder PRIVATE PerfectNumber)
