#include <vector>
#include <iostream>
#include "HeapPriorityQueue.hpp"

heapQueue::heapQueue(std::vector<std::pair<double, double>> array) {
    arr = array;
};

void heapQueue::heapifyUp(int i) {
    if(i > 0) {
        int parent = (i - 1) / 2;

        if(arr[parent].second < arr[i].second) {
        std::swap(arr[i], arr[parent]);

        heapifyUp(parent);
        }
    }
}

void heapQueue::insert(double e, double p) {
    std::pair<double, double> newElem = {e, p};
    arr.push_back(newElem);
    heapifyUp(arr.size() - 1);
}