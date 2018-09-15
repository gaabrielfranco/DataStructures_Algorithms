#include <climits>
#include <iostream>

template <class T>
bool defaut_comp(T a, T b)
{
    return a < b;
}

template <class T>
void selection_sort(T A[], size_t n, size_t k, bool (*comp)(T, T) = defaut_comp)
{
    size_t min;
    T aux;
    for (size_t i = 0; i < k; i++)
    {
        min = i;
        for (size_t j = i + 1; j < n; j++)
        {
            if (comp(A[j], A[min]))
            {
                min = j;
            }
        }
        aux = A[i];
        A[i] = A[min];
        A[min] = aux;
    }
}

template <class T>
void insertion_sort(T A[], size_t n, size_t k, bool (*comp)(T, T) = defaut_comp)
{
    T aux;
    size_t j, pivot;
    for (size_t i = 1; i < n; i++)
    {
        aux = A[i];
        if (i > k - 1)
        {
            pivot = k - 1;
            if (comp(A[i], A[k]))
            {
                A[i] = A[k];
            }
        }
        else
        {
            pivot = i - 1;
        }
        for (j = pivot; j != ULONG_MAX && comp(aux, A[j]); j--)
        {
            A[j + 1] = A[j];
        }

        A[j + 1] = aux;
    }
}
