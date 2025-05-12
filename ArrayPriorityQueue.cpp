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

std::pair<double, double> arrayQueue::find_max() const
{

    int max_Index = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i].second > arr[max_Index].second)
        {
            max_Index = i;
        }
    }

    return arr[max_Index];
}

void arrayQueue::modify_key(double e, double p)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i].first == e)
        {
            arr[i].second = p;
            break;
        }
    }
}

int arrayQueue::return_size() const
{
    return arr.size();
}
