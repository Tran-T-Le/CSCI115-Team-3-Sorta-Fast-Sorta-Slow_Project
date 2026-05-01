# CSCI-115-Final-Project
- CSCI 115 - Algorithms and Data Structures 
- Team 3: Sorta Fast, Sorta Slow
- Members: Fnu Gurleen Kaur, Tran Thanh Dat Le, Vickydel Samantha Gutierrez 
---
# Language, Dependencies and Environment
- Language: C++
- Recommend Standard: C++17
- Compiler: g++ or any compiler that works with C++17
- Enviroment used: console & terminal program, compatible with Visual Studio Code, CodeBlocks or any command line builds
- Dependencies:
  - Part 1:
    - iostream 
    - ctime
    - cstdlib 
    - algorithm
  - Part 2:
    - iostream
    - vector
    - algorithm 
---
## 1. Project Overview
- This project studies how the theoretical time complexity of sorting algorithms compares to actual measured runtime and is divided into 2 parts:

**Part 1**: studies algorithm and compares theoretical runtime with actual measured runtime (average runtime across 5 runs)

**Part 2**: Using the two sum method to solve the following problem:
> Problem: Given a set S of n integers and an integer x, determine whether there exist two elements in S whose sum is exactly x.

- The goal of Part 2 is to show:
  - one "brute force" approach
  - one "more efficient" approach
  - compare how the two approaches are different in logic and time complexity analysis
 
---
## 2. Project Goals
- Compare theoretical analysis with actual measured performance
- Study sorting algorithms with different values input conditions
- Analyze best-case, average-case, worst-case behavior between sorting algorithm
- Practice brute-force and efficent design
- Create proper documentation and graphs for the final report (Excel document)
---
## 3. Files Included in the Project
### Part 1:
- 'main.cpp'
  - main sorting driver
- 'BubbleSort.cpp'
  - Bubble Sort algorithm
- 'SelectionSort.cpp'
  - Selection Sort algorithm
- 'InsertionSort.cpp'
  - Insertion Sort algorithm
- 'MergeSort.cpp'
  - Merge Sort algorithm
- 'QuickSort.cpp'
  - Quick Sort algorithm
- 'CountingSort.cpp'
  - Counting Sort algorithm
- 'RadixSort.cpp'
  - Radix Sort algorithm

### Part 2:
- 'Twosum.cpp'
   - main driver for two sum problem
- 'Twosum.h'
  - header file for two sum 
---
### 4. Sorting Algorithms in the Project
1. Bubble Sort
2. Selection Sort
3. Insertion Sort
4. Merge Sort
5. Quick Sort
6. Heap Sort
7. Counting Sort
8. Radix Sort

--- 
## What the Program Does

Part 1:
1. Runs correctness tests for all sorting algorithms
2. Asks the user to choose an input size
3. Asks the user to choose an input type
4. Asks the user to choose a sorting algorithm
5. Runs the selected algorithm
6. Measures execution time
7. Print the time in millisecond
8. Print the first 20 values of the sorted result
9. Allows the user run another test without rebuilding
 
Part 2:
1. 


---
## Input Sizes
The program supported these array sizes:
- 100
- 1,000
- 10,000
- 100,000
- 500,000

--- 
## Input Types
The program offers 3 input types per sorting algorithm:
- [ Best Case ] - already sorted
- [ Average Case ] - random values
- [ Worst Case ] - reverse sorted

---
## 5. Program Features
### Part 1: Time Complexity / Running Time Analysis
- correctness testing
- input size selection menu
- input type selection menu
- sorting algorithm selection menu
- runtime measurements (in miliseconds)
- sorted output preview
- repeat menu

### Part 2:
- Contains:
- 'bruteForce' the brute force approach -> time complexity of O(n^2)
- 'twoPointer' the more efficient approach -> time complexity of O(nlogn)
- The Twosum.h header contain helper functions that are used ot print sample test cases and run a few correctness checks for brute force

---
## Notes, Assumptions, Limitations and Known Issues

### Assumptions:
- Part 1 assumes input elements are integers in the range of [0, n-1]
- Part 2 uses provided sampled integer input values and checks whether any two sum to the target
- Part 2 uses one sample vector and is interactive based on the user's input
### Limitations:
- Part 1 timing and data is collected manually aacross 5 runs and only run one run at a time
### Known Issues:
- Certain sorting algorithms such as Quicksort and Insertion Sort are unable to handle our maximum data input range of 500,000 and would take a lot of time to finalize.
