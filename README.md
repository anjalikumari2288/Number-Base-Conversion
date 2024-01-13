# Number-Base-Conversion
Cosnole based C program to convert a number from a given base to a target base.  Additionally, it includes a testing framework to ensure the correctness of the conversion functions.

## Learning Goals
- Understand the process of converting numbers between different bases.
- Learn about handling special cases.
- Gain experience with string manipulation and array operations in C.
- Practice writing and executing unit tests for code validation.

## Constraints
- Supports bases from 2 to 36, using digits 0-9 and characters A-Z, bases beyond 36 are not supported.

## Why no base 1?
Binary (base-2), there are two digits (0 and 1). A base-1 system would mean having only one digit or symbol to represent numbers. The problem with base-1 is that there is no distinction between different values, making it challenging to represent meaningful numbers or perform mathematical operations.

## Run program
- Compile
  ```
  gcc -o number_base_conversion_driver number_base_conversion_driver.c
  ```
- Run the compiled
  ```
   ./number_base_conversion_driver
  ```
