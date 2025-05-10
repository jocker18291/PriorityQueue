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
    void heapifyUp(int i);
    void heapifyDown(int n, int i);
    void insert(double e, double p);
    std::pair<double, double> extract_max();
};

#endif