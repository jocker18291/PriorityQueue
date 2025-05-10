#include <vector>
#include <iostream>
#include "HeapPriorityQueue.hpp"

heapQueue::heapQueue(std::vector<std::pair<double, double>> array) {
    arr = array;
};

void heapQueue::heapify(std::vector<std::pair<double, double>>& arr, int n, int i) {

    int largest = i;

    int left = 2 * i + 1;

    int right = 2 * 1 + 2;

    if(arr[largest] < arr[left] && left < n) {
        largest = left;
    }

    if(arr[largest] < arr[right] && right < n) {
        largest = right;
    }

    if(arr[i] != arr[largest]) {
        std::swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}