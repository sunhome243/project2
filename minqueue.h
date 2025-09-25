#ifndef MQ_H
#define MQ_H

#include <string>
#include <sstream>
using namespace std;

template <typename T>
class MinQueue
{
public:
    MinQueue();
    MinQueue(const T *A, int n);
    ~MinQueue();
    void sort();

private:
    T *arr;
    int size;
    int capacity;

    int left(int i);
    int right(int i);
    int parent(int i);
    void build_min_heap();
    void heapify(int i);
    void heapsort(T *A);
    void swap(int index1, int index2);
    void max_heapify(int i);
};

#include "minqueue.cpp"

#endif