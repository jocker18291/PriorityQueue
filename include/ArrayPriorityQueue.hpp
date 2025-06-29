#ifndef ARRAYPRIORITYQUEUE_HPP
#define ARRAYPRIORITYQUEUE_HPP
#include <utility>

class arrayQueue
{
private:
    std::pair<double, double>* arr;
    int size;
    int capacity;
    
public:
    arrayQueue();
    ~arrayQueue();
    void resize();
    void insert(double e, double p);
    std::pair<double, double> extract_max();
    std::pair<double, double> find_max() const;
    void modify_key(double e, double p);
    int return_size() const;
};

#endif