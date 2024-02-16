# PerfectNumberFinder

## Introduction
The `PerfectNumberFinder` application is designed to efficiently identify perfect numbers within a given set of integers. A perfect number is a positive integer that is equal to the sum of its proper positive divisors, excluding the number itself. For example, 28 is a perfect number because its divisors (1, 2, 4, 7, 14) sum up to 28.

This project has two goals:
1. **Demonstrate Efficient Parallel Computing**: By using multi-threading, the application showcases how to divide a computational task into smaller chunks and process them concurrently, significantly reducing the overall processing time for large datasets.
2. **Apply Modern C++ Practices**: The project is implemented using C++17 features, adhering to modern best practices in C++ development. It serves as a practical example of using advanced C++ concepts.

## Features
- Multi-threaded processing to efficiently handle large datasets.
- Utilizes C++17 standard for modern C++ practices.
- Easy to build and run with minimal dependencies.
- Optimized for performance by avoiding the use of atomic variables, thus reducing the overhead associated with atomic operations in multi-threaded environments.

## Prerequisites
Ensure you have the following installed:
- C++17 compliant compiler
- CMake (version 3.20 or higher)

## Building the Application
To compile `PerfectNumberFinder`, follow these steps:

```bash
mkdir build && cd build  # Create a build directory
cmake ..                 # Generate Makefiles
make                     # Compile the project
```

## Running the Unit Tests
Follow these steps to compile and run the unit tests for the project:

```bash
git submodule update --init --recursive     # Initialize the Google Test submodule
mkdir build && cd build                     # Create a build directory
cmake -DBUILD_TESTS=ON ..                   # Generate Makefiles and enable unit tests. 
make                                        # Compile the project
ctest -V                                    # Run the Unit Tests with CTest
```

## Running the Application
After building, you can run the application using:
```bash
./build/PerfectNumberFinder <path-to-number-file> <number-of-threads>
```
* \<path-to-number-file\>: Specifies the path to the text file containing integers, with one number per line.
* \<number-of-threads\>: Indicates how many threads the application should use for processing.

## Usage Example
```bash
./build/PerfectNumberFinder ./numbers.txt 5
```
This command will process numbers from numbers.txt using 5 threads.


## Architecture

The `PerfectNumberFinder` application follows a modular and multi-threaded architecture, designed for clarity, maintainability, and performance. The architecture is divided into several key components:

1. **Main Application (`main.cpp`)**: The entry point of the application, responsible for parsing command-line arguments, reading the input file, and initializing the core components.

2. **Number Reader (`NumberReader.cpp`/`NumberReader.h`)**: This module is responsible for reading the set of integers from a file. It validates the input to ensure that each line contains a valid integer.

3. **Perfect Number Checker (`PerfectNumber.cpp`/`PerfectNumber.h`)**: Contains the logic to determine whether a given number is perfect.

4. **Thread Manager (`ThreadManager.cpp`/`ThreadManager.h`)**: Manages a pool of worker threads, distributing workload and ensuring data consistency across threads. It divides the input set among a specified number of worker threads and aggregates their results. Optimized for performance by avoiding the use of atomic variables, thus reducing the overhead associated with atomic operations in multi-threaded environments.

5. **Unit Tests**: Located in the `tests` directory, these provide a suite of test cases for the application's core functionalities, ensuring reliability and correctness. The tests cover various scenarios, including edge cases, to validate the integrity of the number reading, perfect number checking, and multi-threading logic.

The application is built using CMake, making it easy to build on different platforms. A `CMakeLists.txt` file at the root defines the build configuration, including compiler settings, source files, and dependencies.

