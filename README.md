# PerfectNumberFinder

## Introduction
`PerfectNumberFinder` is a multi-threaded application designed to efficiently identify perfect numbers within a large set of integers. Utilizing modern C++ features, this program demonstrates the power of parallel computing in processing intensive tasks.

## Features
- Multi-threaded processing to efficiently handle large datasets.
- Utilizes C++17 standard for modern C++ practices.
- Easy to build and run with minimal dependencies.

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

## Running the Application
After building, you can run the application using:
```bash
./build/PerfectNumberFinder <path-to-number-file> <number-of-threads>
```
* <path-to-number-file>: Specifies the path to the text file containing integers, with one number per line.
* <number-of-threads>: Indicates how many threads the application should use for processing.

## Usage Example
```bash
./build/src/PerfectNumberFinder ../tests/numbers.txt 10
```
This command will process numbers from numbers.txt using 10 threads.