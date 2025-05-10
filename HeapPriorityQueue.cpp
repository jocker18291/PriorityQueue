#include <vector>
#include <iostream>
#include "HeapPriorityQueue.hpp"

heapQueue::heapQueue(std::vector<std::pair<double, double>> array) {
    arr = array;
};

void heapQueue::heapify(std::vector<std::pair<double, double>>& arr, int n, int i) {

    int largest = i;

    int left = 2 * i + 1;

    int right = 2 * i + 2;

    if(left < n && arr[largest].second < arr[left].second) {
        largest = left;
    }

    if(right < n && arr[largest].second < arr[right].second) {
        largest = right;
    }

    if(largest != i) {
        std::swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}