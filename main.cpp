#include "HeapPriorityQueue.hpp"
#include <iostream>

void heapMenu() {
    heapQueue hq;
    double e = 0.0, p = 0.0;
    int choice = 0;
    std::cout << " --- Heap Priority Queue ---\n\n";
    std::cout << "1. Insert an element (e, q)\n";
    std::cout << "2. Extract the biggest element\n";
    std::cin >> choice;
    switch(choice) {
        case 1:
            std::cout << "Enter an element and a priority: ";
            std::cin >> e >> p;
            hq.insert(e, p);
            break;
        case 2:
            std::cout << "The biggest element: " << hq.extract_max().first << " with priority of " << hq.extract_max().second << std::endl;
        default:
            break;
    }
}

int main() {

    return 0;
}