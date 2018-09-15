#include <iostream>
#include "sort.h"

int main()
{
    int V[10] = {4, 5, 3, 2, 1, 1, 5, 3, 2, 1};
    insertion_sort(V, 10, 3);
    for (int i = 0; i < 10; i++)
    {
        std::cout << V[i] << " ";
    }
    std::cout << "\n";
    return 0;
}