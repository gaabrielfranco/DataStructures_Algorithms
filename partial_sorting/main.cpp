#include <iostream>
#include "sort.h"

int main()
{
    int V[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    // int V[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    quick_sort(V, 10, 10);
    for (int i = 0; i < 10; i++)
    {
        std::cout << V[i] << " ";
    }
    std::cout << "\n";
    return 0;
}