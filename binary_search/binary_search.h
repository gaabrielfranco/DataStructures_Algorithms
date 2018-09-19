#include <climits>
#include <iostream>

template <class T>
long long binary_search(T v[], size_t n, T value)
{
    int left, mid, right;
    left = 0;
    right = n - 1;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (v[mid] == value)
        {
            return mid;
        }
        if (v[mid] < value)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return ULLONG_MAX;
}

template <class T>
size_t binary_search(T v[], size_t left, size_t right, T value)
{
    if (left <= right)
    {
        size_t mid = (left + right) / 2;
        if (v[mid] == value)
        {
            return mid;
        }
        else if (v[mid] < value)
        {
            return binary_search(v, mid + 1, right, value);
        }
        else
        {
            return binary_search(v, left, mid - 1, value);
        }
    }
    else
    {
        return ULLONG_MAX;
    }
}