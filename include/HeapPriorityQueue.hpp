#ifndef HEAPPRIORITYQUEUE_HPP
#define HEAPPRIORITYQUEUE_HPP
#include <utility>

class heapQueue {
private:
    std::pair<double, double>* arr;
    int size;
    int capacity;
public:
    heapQueue();
    ~heapQueue();
    void heapifyUp(int i);
    void heapifyDown(int i);
    void resize();
    void insert(double e, double p);
    std::pair<double, double> extract_max();
    std::pair<double, double> find_max() const;
    void modify_key(double e, double p);
    int return_size() const;
};

#endif