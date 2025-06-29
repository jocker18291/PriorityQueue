#include <vector>
#include <iostream>
#include "HeapPriorityQueue.hpp"

heapQueue::heapQueue() {
    capacity = 10;
    size = 0;
    arr = new std::pair<double, double>[capacity];
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

void heapQueue::heapifyDown(int i) {
    int largest = i;

    int left = 2 * i + 1;

    int right = 2 * i + 2;

    if(left < size && arr[largest].second < arr[left].second) {
        largest = left;
    }

    if(right < size && arr[largest].second < arr[right].second) {
        largest = right;
    }

    if(largest != i) {
        std::swap(arr[i], arr[largest]);

        heapifyDown(largest);
    }
}

void heapQueue::resize() {
    if(size == capacity) {
        std::pair<double, double>* NewArr = new std::pair<double, double>[capacity * 2];
        capacity *= 2;
        for(int i = 0; i < size; i++) {
            NewArr[i] = arr[i];
        }
        delete[] arr;
        arr = NewArr;
    }
}

void heapQueue::insert(double e, double p) {
    if(size == capacity) resize();
    arr[size] = {e, p};
    heapifyUp(size);
    size++;
}

std::pair<double, double> heapQueue::extract_max() {
    std::pair<double, double> firstElem = arr[0];
    std::swap(arr[0], arr[size - 1]);
    size--;
    heapifyDown(0);
    return firstElem;
}

std::pair<double, double> heapQueue::find_max() const {
    return arr[0];
}

void heapQueue::modify_key(double e, double p) {
    double currentP = 0;
    for(int i = 0; i < size; i++) {
        if(arr[i].first == e) {
            currentP = arr[i].second;
            arr[i].second = p;
            if(currentP > p) {
                heapifyDown(i);
            }
            else if (currentP < p) {
                heapifyUp(i);
            }
            break;
        }
    }
    
}



heapQueue::~heapQueue() {
    delete[] arr;
}

int heapQueue::return_size() const {
    return size;
}
