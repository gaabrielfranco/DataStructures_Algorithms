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

    for (size_t i = n - 1, j = 0; j < (k / 2); i--, j++)
    {
        aux = A[i];
        A[i] = A[j];
        A[j] = aux;
    }
}

template <class T>
size_t partition(T A[], size_t p, size_t r, size_t k,
                 bool (*comp)(T, T) = defaut_comp)
{
    std::random_device random_device;
    std::mt19937 engine{random_device()};
    std::uniform_int_distribution<size_t> dist(p, r);
    size_t random_element = dist(engine);

    T aux = A[p];
    A[p] = A[random_element];
    A[random_element] = aux;

    T pivot = A[p];
    size_t q = p;
    for (size_t i = p + 1; i <= r; i++)
    {
        if (comp(A[i], pivot))
        {
            q++;
            aux = A[q];
            A[q] = A[i];
            A[i] = aux;
        }
    }
    aux = A[q];
    A[q] = A[p];
    A[p] = aux;
    return q;
}

template <class T>
void q_sort(T A[], size_t p, size_t r, size_t k,
            bool (*comp)(T, T) = defaut_comp)
{
    if (p < r)
    {
        size_t q = partition(A, p, r, k, comp);
        if (q - p + 1 >= k)
        {
            q_sort(A, p, q, k, comp);
        }
        else
        {
            q_sort(A, p, q, k, comp);
            q_sort(A, q + 1, r, k, comp);
        }
    }
}

template <class T>
void quick_sort(T A[], size_t n, size_t k, bool (*comp)(T, T) = defaut_comp)
{
    q_sort(A, 0, n - 1, k, comp);
}
