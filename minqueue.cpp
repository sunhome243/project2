#ifndef MQ_CPP
#define MQ_CPP

#include "minqueue.h"

template <typename T>
MinQueue<T>::MinQueue() : arr(nullptr), size(0), capacity(0)
{
}

template <typename T>
MinQueue<T>::MinQueue(const T *A, int n) : arr(nullptr), size(0), capacity(0)
{
    if (n > 0 && A)
    {
        capacity = n;
        size = n;
        arr = new T[capacity];
        for (int i = 0; i < n; i++)
        {
            arr[i] = A[i];
        }
        build_min_heap();
    }
}

template <typename T>
MinQueue<T>::~MinQueue()
{
    if (arr)
    {
        delete[] arr;
    }
}

template <typename T>
int MinQueue<T>::left(int i)
{
    return 2 * i + 1;
}

template <typename T>
int MinQueue<T>::right(int i)
{
    return 2 * i + 2;
}

template <typename T>
int MinQueue<T>::parent(int i)
{
    return (i - 1) / 2;
}

template <typename T>
void MinQueue<T>::build_min_heap()
{
    for (int i = (size - 1) / 2; i >= 0; i--)
    {
        heapify(i);
    }
}

template <typename T>
void MinQueue<T>::heapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;

    if (l < size && arr[l] < arr[smallest])
    {
        smallest = l;
    }

    if (r < size && arr[r] < arr[smallest])
    {
        smallest = r;
    }

    if (smallest != i)
    {
        swap(i, smallest);
        heapify(smallest);
    }
}

template <typename T>
void MinQueue<T>::sort()
{
    heapsort(arr);
}

template <typename T>
void MinQueue<T>::swap(int index1, int index2)
{
    T temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}

template <typename T>
void MinQueue<T>::heapsort(T *A)
{
    int original_size = size;

    // Build max heap for ascending sort
    for (int i = (size - 1) / 2; i >= 0; i--)
    {
        max_heapify(i);
    }

    for (int i = size - 1; i > 0; i--)
    {
        swap(0, i);
        size--;
        max_heapify(0);
    }

    // Copy sorted array to A
    for (int i = 0; i < original_size; i++)
    {
        A[i] = arr[i];
    }

    // Restore original size and min heap property
    size = original_size;
    build_min_heap();
}

template <typename T>
void MinQueue<T>::max_heapify(int i)
{
    int l = left(i);
    int r = right(i);
    int largest = i;

    if (l < size && arr[l] > arr[largest])
    {
        largest = l;
    }

    if (r < size && arr[r] > arr[largest])
    {
        largest = r;
    }

    if (largest != i)
    {
        swap(i, largest);
        max_heapify(largest);
    }
}

#endif