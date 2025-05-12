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

std::vector<std::pair<double, double>> generateRandom(int n) {
    std::vector<std::pair<double, double>> arr;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> element(-100, 100);
    std::uniform_real_distribution<> priority(-100, 100);

    for(int i = 0; i < n; i++) {
        arr.push_back({element(gen), priority(gen)});
    }

    return arr;
}

int TRIALS = 100;

void testQueueInsert() {
    double totalHeap = 0.0, totalArray = 0.0;
    std::string fileName;
    heapQueue hq;
    arrayQueue aq;

    std::cout << "\n --- Testing Queues ---\n\n";
    std::cout << "Enter the file name to save results: ";
    std::cin >> fileName;
    std::ofstream MyFile(fileName);

    MyFile << "Size,HeapTime,ArrTime" << std::endl;

    std::vector<int> size = {1000, 10000, 50000, 100000, 500000, 1000000};

    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < TRIALS; j++) {
            auto arr = generateRandom(size[i]);
            auto relem = generateRandom(1);

            for(auto element : arr) {
                hq.insert(element.first, element.second);
                aq.insert(element.first, element.second);
            }

            auto start = std::chrono::high_resolution_clock::now();
            hq.insert(relem[0].first, relem[0].second);
            auto end = std::chrono::high_resolution_clock::now();
            totalHeap += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

            auto start2 = std::chrono::high_resolution_clock::now();
            aq.insert(relem[0].first, relem[0].second);
            auto end2 = std::chrono::high_resolution_clock::now();
            totalArray += std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - start2).count();
        }
        MyFile << size[i] << "," << totalHeap/TRIALS << "," << totalArray/TRIALS << std::endl;
    }
    MyFile.close();
}

int main()
{
    int choice = 0;

    std::cout << "1. Use Heap-based Priority Queue\n";
    std::cout << "2. Use Array-based Priority Queue\n";
    std::cout << "3. Test Insert on Both Queues\n";
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
    case 3:
        testQueueInsert();
        break;
    default:
        std::cout << "Unknown choice, try again\n";
        break;
    }
    return 0;
}