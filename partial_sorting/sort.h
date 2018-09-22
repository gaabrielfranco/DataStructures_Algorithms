#include <climits>
#include <iostream>
#include <random>

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

template <class T>
void heapify(T A[], size_t n, size_t root, bool (*comp)(T, T) = defaut_comp)
{
    size_t smallest = root;
    size_t left = 2 * root + 1;
    size_t right = 2 * root + 2;

    if (left < n && comp(A[left], A[smallest]))
    {
        smallest = left;
    }

    if (right < n && comp(A[right], A[smallest]))
    {
        smallest = right;
    }

    if (smallest != root)
    {
        T aux = A[root];
        A[root] = A[smallest];
        A[smallest] = aux;
        heapify(A, n, smallest);
    }
}

template <class T>
void heap_sort(T A[], size_t n, size_t k, bool (*comp)(T, T) = defaut_comp)
{
    T aux;

    for (size_t i = (n / 2) - 1; i != ULONG_MAX; i--)
    {
        heapify(A, n, i);
    }

    if (k < n)
    {
        for (size_t i = n - 1; i >= (n - k); i--)
        {
            aux = A[0];
            A[0] = A[i];
            A[i] = aux;
            heapify(A, i, 0);
        }
    }
    else
    {
        for (size_t i = n - 1; i > (n - k); i--)
        {
            aux = A[0];
            A[0] = A[i];
            A[i] = aux;
            heapify(A, i, 0);
        }
    }

    /*for (size_t i = n - 1, j = 0; j < (k / 2); i--, j++)
    {
        aux = A[i];
        A[i] = A[j];
        A[j] = aux;
    }*/
}

template <class T>
long partition(T A[], size_t l, size_t r, bool (*comp)(T, T) = defaut_comp)
{
    T aux;
    long i = l - 1;
    long j = r;
    T v = A[r];

    for (;;)
    {
        while (comp(A[++i], v))
            ;
        while (comp(v, A[--j]))
        {
            if (j == l)
            {
                break;
            }
        }
        if (i >= j)
        {
            break;
        }
        aux = A[i];
        A[i] = A[j];
        A[j] = aux;
    }
    aux = A[i];
    A[i] = A[r];
    A[r] = aux;
    return i;
}

template <class T>
void q_sort(T A[], long l, long r, size_t k, bool (*comp)(T, T) = defaut_comp)
{
    if (l < r)
    {
        long i = partition(A, l, r, comp);
        if (i - l + 1 > k)
        {
            q_sort(A, l, i - 1, k, comp);
        }
        else
        {
            q_sort(A, l, i - 1, k, comp);
            q_sort(A, i + 1, r, k, comp);
        }
    }
}

template <class T>
void quick_sort(T A[], size_t n, size_t k, bool (*comp)(T, T) = defaut_comp)
{
    q_sort(A, 0, n - 1, k, comp);
}