# PriorityQueue

This project implements and benchmarks two types of priority queue data structures in C++:

- **Heap-based Priority Queue** (`heapQueue`)
- **Array-based Priority Queue** (`arrayQueue`)

Both implementations support the following operations:
- Insert an element with a given priority
- Extract the element with the maximum priority
- Find the element with the maximum priority (without removal)
- Modify the priority of an existing element
- Get the current size of the queue

## Features

- **Heap-based Queue**: Efficiently manages elements using a binary heap, ensuring `O(log n)` insertion and extraction.
- **Array-based Queue**: Manages elements in an unsorted array, with `O(1)` insertion and `O(n)` extraction.
- **Benchmarking**: The project includes benchmarking tools to compare the performance of both implementations for various queue operations and input sizes.
- **CLI Menus**: Interactive console menus to test and demonstrate each implementation.

## Usage

1. **Compile the project**  
   Ensure you have a C++ compiler (such as `g++`):

   ```sh
   g++ -std=c++11 main.cpp ArrayPriorityQueue.cpp HeapPriorityQueue.cpp -o PriorityQueue
   ```

2. **Run the executable**  
   ```sh
   ./PriorityQueue
   ```

3. **Menu Options**  
   The program presents a menu allowing you to:
   - Use Heap-based or Array-based priority queue
   - Test and benchmark `Insert`, `Extract_Max`, `Find_Max`, `Modify`, and `Return Size` on both queues

   Outputs from benchmarking are saved to CSV files as prompted.

## Code Structure

- `HeapPriorityQueue.hpp/cpp`: Implements a max-priority queue with a binary heap.
- `ArrayPriorityQueue.hpp/cpp`: Implements a max-priority queue using an unsorted array.
- `main.cpp`: Contains the interactive menu, benchmarking routines, and test drivers.

## Example: Benchmarking Insert

The benchmarking functions (e.g., `testQueueInsert()`) generate random elements and measure the time taken by both implementations to perform operations for increasing queue sizes. Results are saved in CSV format for further analysis.

## Example: Using the Heap-based Queue

```cpp
heapQueue hq;
hq.insert(5.0, 10.0); // Insert element 5.0 with priority 10.0
auto maxElem = hq.extract_max(); // Removes and returns the element with the highest priority
```

## Requirements

- C++11 or newer
- Standard libraries: `<iostream>`, `<vector>`, `<utility>`, `<random>`, `<chrono>`, `<fstream>`

## License

This project is provided without warranty. You may use or modify it as needed.

---

*Created for educational purposes to compare and benchmark priority queue implementations.*
