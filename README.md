# PerfectNumberFinder

## Introduction
`PerfectNumberFinder` is a multi-threaded application designed to efficiently identify perfect numbers within a large set of integers.

## Features
- Multi-threaded processing to efficiently handle large datasets.
- Utilizes C++17 standard for modern C++ practices.
- Easy to build and run with minimal dependencies.

## Prerequisites
Ensure you have the following installed:
- C++17 compliant compiler
- CMake (version 3.20 or higher)

## Initialize Submodules

```bash
git submodule update --init --recursive
```

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
mkdir build && cd build     # Create a build directory
cmake -DBUILD_TESTS=ON ..   # Generate Makefiles and enable unit tests. 
make                        # Compile the project
ctest -V                    # Run the Unit Tests with CTest
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