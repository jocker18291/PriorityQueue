#ifndef HEAPPRIORITYQUEUE_HPP
#define HEAPPRIORITYQUEUE_HPP
#include <vector>

class heapQueue {
private:
    double element;
    double priority;
    std::vector<std::pair<double, double>> arr;
public:
    heapQueue();
    void heapifyUp(int i);
    void heapifyDown(int n, int i);
    void insert(double e, double p);
    std::pair<double, double> extract_max();
    std::pair<double, double> find_max() const;
    void modify_key(double e, double p);
    int return_size() const;
};

#endif