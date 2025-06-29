#include "../include/ArrayPriorityQueue.hpp"
#include <iostream>
#include <utility>

arrayQueue::arrayQueue()
{
    capacity = 10;
    size = 0;
    arr = new std::pair<double, double>[capacity];
}

void arrayQueue::insert(double e, double p)
{
    if (size == capacity)
    {
        resize();
    }
    arr[size] = { e, p };
    size++;
}

std::pair<double, double> arrayQueue::extract_max()
{
    int max_Index = 0;
    for (int i = 1; i < size; i++)
    {
        if (arr[i].second > arr[max_Index].second)
        {
            max_Index = i;
        }
    }
    std::pair<double, double> max_Elem = arr[max_Index];

    for (int i = max_Index; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    size--;
    return max_Elem;
}

std::pair<double, double> arrayQueue::find_max() const
{
    int max_Index = 0;
    for (int i = 1; i < size; i++)
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
    for (int i = 0; i < size; i++)
    {
        if (arr[i].first == e)
        {
            arr[i].second = p;
            break;
        }
    }
}

void arrayQueue::resize()
{
    if (size == capacity) {
        capacity *= 2;
        std::pair<double, double>* NewArr = new std::pair<double, double>[capacity];
        for (int i = 0; i < size; ++i)
        {
            NewArr[i] = arr[i];
        }
        delete[] arr;
        arr = NewArr;
    }
}

arrayQueue::~arrayQueue()
{
    delete[] arr;
}

int arrayQueue::return_size() const
{
    return size;
}