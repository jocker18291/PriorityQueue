#include "ArrayPriorityQueue.hpp"
#include <iostream>

arrayQueue::arrayQueue() {}

void arrayQueue::insert(double e, double p)
{
    arr.push_back({e, p});
}

std::pair<double, double> arrayQueue::extract_max()
{
    int max_Index = 0;
    for (int i = 1; i < arr.size(); i++) 
    {
        if (arr[i].second > arr[max_Index].second) 
        {
            max_Index = i;
        }
    }
    std::pair<double, double> max_Elem = arr[max_Index];
    arr.erase(arr.begin() + max_Index);
    return max_Elem;
}