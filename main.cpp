#include "HeapPriorityQueue.hpp"
#include <iostream>

void heapMenu() {
    heapQueue hq;
    double e = 0.0, p = 0.0;
    int choice = 0;
    std::cout << " --- Heap Priority Queue ---\n\n";
    std::cout << "1. Insert an element (e, q)\n";
    std::cout << "2. Extract the biggest element\n";
    std::cout << "3. Find the element of the biggest priority\n";
    std::cout << "4. Modify the priority of given element\n";
    std::cout << "5. Return the size of the heap\n";
    std::cin >> choice;
    switch(choice) {
        case 1:
            std::cout << "Enter an element and a priority: ";
            std::cin >> e >> p;
            hq.insert(e, p);
            break;
        case 2:
            std::cout << "The biggest element: " << hq.extract_max().first << " with priority of " << hq.extract_max().second << " was deleted\n";
            break;
        case 3:
            std::cout << "Element with the biggest priority: " << hq.find_max().first << " with priority of " << hq.find_max().second << std::endl;
            break;
        case 4:
            std::cout << "Enter the element and a priority to change: ";
            std::cin >> e >> p;
            hq.modify_key(e, p);
            break;
        case 5:
            std::cout << "The size of the heap: " << hq.return_size() << std::endl;
            break;
        default:
            break;
    }
}

int main() {
    heapMenu();
    
    return 0;
}