#ifndef HEAPPRIORITYQUEUE_HPP
#define HEAPPRIORITYQUEUE_HPP
#include <vector>

class heapQueue {
private:
    double element;
    double priority;
    std::vector<std::pair<double, double>> arr;
public:
    heapQueue(std::vector<std::pair<double, double>> arr);
    void heapify(std::vector<std::pair<double, double>>& arr, int n, int i);
};

#endif