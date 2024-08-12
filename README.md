# Memory Allocation Example

## Overview

This project demonstrates a simple custom memory allocator and deallocator in C. It includes a memory management system that simulates allocation and deallocation of memory blocks using a custom `MyMalloc` and `MyFree` functions.

## Features

- **Custom Memory Allocation:** Implements a basic memory allocation mechanism with the ability to allocate and free memory blocks of varying sizes.
- **Memory Management:** Handles memory block splitting and merging to optimize space usage.
- **Simulation:** Provides a simple simulation of memory allocation and deallocation in a fixed-size memory array.

## Files

- **`main.c`**: Contains the test code that demonstrates the usage of the custom memory allocator.
- **`mymalloc.c`**: Implements the custom memory allocator functions.
- **`mymalloc.h`**: Header file declaring the custom memory allocator functions and the block structure.

## Compilation and Execution

1. **Compilation:**
   - To compile the project, use the following command:
     ```bash
     gcc -o memory_example main.c mymalloc.c
     ```

2. **Execution:**
   - Run the compiled executable using the following commands:
     - **Windows:**
       ```bash
       ./memory_example.exe
       ```
     - **Linux/Mac:**
       ```bash
       ./memory_example
       ```

## File Descriptions

- **`main.c`**: Demonstrates how to use the `MyMalloc` and `MyFree` functions to allocate and deallocate memory blocks.
- **`mymalloc.c`**: Contains the implementation of the `MyMalloc` and `MyFree` functions along with memory management logic.
- **`mymalloc.h`**: Defines the structure for memory blocks and declares the memory management functions.

## Example Usage

In `main.c`, the following operations are performed:

- Allocate memory for `100` integers.
- Allocate memory for `250` characters.
- Allocate memory for `1000` integers.
- Free the previously allocated memory.
- Allocate more memory for `700` characters.
- Free additional allocated memory.
- Allocate memory for `500` integers.

The program outputs messages indicating successful allocation and deallocation.

## Notes

- Ensure you have GCC installed to compile the program.
- Adjust the memory size and block sizes in `mymalloc.c` as needed.
