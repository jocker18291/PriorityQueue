#include "HeapPriorityQueue.hpp"
#include "ArrayPriorityQueue.hpp"
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <fstream>

void arrayMenu()
{
    arrayQueue aq;
    double e = 0.0, p = 0.0;
    int choice = 0;
    std::pair<double, double> max_Elem;
    do {
        std::cout << "\n --- Array Priority Queue ---\n\n";
        std::cout << "1. Insert an element (e, p)\n";
        std::cout << "2. Extract the biggest element\n";
        std::cout << "3. Find the element of the biggest priority\n";
        std::cout << "4. Modify the priority of given element\n";
        std::cout << "5. Return the size of the array queue\n";
        std::cout << "6. Exit\n\n";
        std::cout << "Your choice: ";

        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout << "Enter an element and a priority: ";
            std::cin >> e >> p;
            aq.insert(e, p);
            break;
        case 2:
            if (aq.return_size() > 0)
            {
                max_Elem = aq.extract_max();
                std::cout << "The biggest element: " << max_Elem.first << " with priority of " << max_Elem.second << " was deleted\n";
            }
            else
            {
                std::cout << "Error: The queue is empty. Cannot extract an element.\n";
            }
            break;
        case 3:
            if (aq.return_size() > 0)
            {
                std::cout << "Element with the biggest priority: " << max_Elem.first << " with priority of " << max_Elem.second << std::endl;
            }
            else
            {
                std::cout << "Error: The queue is empty. No element to find.\n";
            }
            break;
        case 4:
            std::cout << "Enter the element and a priority to change: ";
            std::cin >> e >> p;
            aq.modify_key(e, p);
            break;
        case 5:
            std::cout << "The size of the array queue: " << aq.return_size() << std::endl;
            break;
        case 6:
            break;
        default:
            std::cout << "Unknown choice, try again\n";
            break;
        }
    } while (choice != 6);
}

void heapMenu() {
    heapQueue hq;
    double e = 0.0, p = 0.0;
    int choice = 0;
    std::pair<double, double> max_Elem;
    do {
        std::cout << "\n --- Heap Priority Queue ---\n\n";
        std::cout << "1. Insert an element (e, q)\n";
        std::cout << "2. Extract the biggest element\n";
        std::cout << "3. Find the element of the biggest priority\n";
        std::cout << "4. Modify the priority of given element\n";
        std::cout << "5. Return the size of the heap\n";
        std::cout << "6. Exit\n\n";
        std::cout << "Your choice: ";

        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter an element and a priority: ";
            std::cin >> e >> p;
            hq.insert(e, p);
            break;
        case 2:
            if (hq.return_size() > 0)
            {
                max_Elem = hq.extract_max();
                std::cout << "The biggest element: " << max_Elem.first << " with priority of " << max_Elem.second << " was deleted\n";
            }
            else
            {
                std::cout << "Error: The queue is empty. Cannot extract an element.\n";
            }
            break;
        case 3:
            if (hq.return_size() > 0)
            {
                std::cout << "Element with the biggest priority: " << max_Elem.first << " with priority of " << max_Elem.second << std::endl;
            }
            else
            {
                std::cout << "Error: The queue is empty. No element to find.\n";
            }
            break;
        case 4:
            std::cout << "Enter the element and a priority to change: ";
            std::cin >> e >> p;
            hq.modify_key(e, p);
            break;
        case 5:
            std::cout << "The size of the heap: " << hq.return_size() << std::endl;
            break;
        case 6:
            break;
        default:
            std::cout << "Unknown choice, try again\n";
            break;
        }
    } while (choice != 6);
}

std::vector<double> generateRandom(int n) {
    std::vector<double> arr;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> element(-100, 100);

    for(int i = 0; i < n; i++) {
        arr.push_back(element(gen));
    }

    return arr;
}

int main()
{
    int choice = 0;

    std::cout << "1. Use Heap-based Priority Queue\n";
    std::cout << "2. Use Array-based Priority Queue\n";
    std::cout << "Choose implementation: ";
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        heapMenu();
        break;
    case 2:
        arrayMenu();
        break;
    default:
        std::cout << "Unknown choice, try again\n";
        break;
    }
    return 0;
}