#include <vector>
#include <iostream>
#include "HeapPriorityQueue.hpp"

heapQueue::heapQueue() {};

void heapQueue::heapifyUp(int i) {
    if(i > 0) {
        int parent = (i - 1) / 2;

        if(arr[parent].second < arr[i].second) {
        std::swap(arr[i], arr[parent]);

        heapifyUp(parent);
        }
    }
}

void heapQueue::heapifyDown(int n, int i) {
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

        heapifyDown(n, largest);
    }
}

void heapQueue::insert(double e, double p) {
    std::pair<double, double> newElem = {e, p};
    arr.push_back(newElem);
    heapifyUp(arr.size() - 1);
}

std::pair<double, double> heapQueue::extract_max() {
    std::pair<double, double> firstElem = arr[0];
    std::swap(arr[0], arr[arr.size() - 1]);
    arr.pop_back();
    heapifyDown(arr.size(), 0);
    return firstElem;
}

double heapQueue::find_max() const {
    return arr[0].first;
}

void heapQueue::modify_key(double e, double p) {
    double currentP = 0;
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i].first == e) {
            currentP = arr[i].second;
            arr[i].second = p;
            if(currentP > p) {
                heapifyDown(arr.size(), i);
            }
            else if (currentP < p) {
                heapifyUp(i);
            }
            break;
        }
    }
    
}

int heapQueue::return_size() const {
    return arr.size();
}