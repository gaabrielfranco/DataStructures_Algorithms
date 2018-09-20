#include <chrono>
#include <cstdlib>
#include <iostream>
#include "sort.h"
typedef std::chrono::high_resolution_clock Clock;

int main(int argc, char** argv)
{
    if (argc > 1)
    {
        long n = strtol(argv[1], nullptr, 10);
        long k_values[3] = {100, 1000, 10000};
        long* A = (long*)malloc(n * sizeof(int));

        for (size_t i = 0; i < n; i++)
        {
            scanf("%ld", &A[i]);
        }

        auto start = Clock::now();
        quick_sort(A, n, 100);
        auto end = Clock::now();

        std::cout << "Quicksort duration: ";
        std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(
                         end - start)
                         .count();
        std::cout << "ms\n";
    }
    else
    {
        std::cout << "Informe o tamanho do vetor\n";
    }
    return 0;
}