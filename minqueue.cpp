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
    for (i = (n - 1) / 2; i > 1; i--)
    {
        heapify(i)
    }
}

template <typename T>
void MinQueue<T>::heapify(int i)
{
    left_item = left(i);
    right_item = right(i);
    current_item = A[i];
    if (left(i) > A[i])
    {
        largest = left(i);
    }
    else
    {
        largest = A[i];
    }

    if (right(i) > A[i])
    {
        largest = right_item
    }

    if (largest != i)
    {
        heapify(largest)
    }
    else
    {
        return
    }
}