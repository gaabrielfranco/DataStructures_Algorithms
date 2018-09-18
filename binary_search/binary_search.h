#include <iostream>

template <class T>
long long binary_search(T v[], size_t n, T value)
{
    int left, mid, rigth;
    left = 0;
    rigth = n - 1;
    while (left <= rigth)
    {
        mid = (left + rigth) / 2;
        if (v[mid] == value)
            return mid;
        if (v[mid] < value)
            left = mid + 1;
        else
            rigth = mid - 1;
    }
    return -1;
}