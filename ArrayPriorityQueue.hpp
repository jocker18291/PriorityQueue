#ifndef ARRAYPRIORITYQUEUE_HPP
#define ARRAYPRIORITYQUEUE_HPP

#include <vector>

class arrayQueue
{
private:
    double element;
    double priority;
    std::vector<std::pair<double, double>> arr;
public:
    arrayQueue();
    void insert(double e, double p);
    std::pair<double, double> extract_max();
    std::pair<double, double> find_max() const;
    void modify_key(double e, double p);
    int return_size() const;
};

#endif