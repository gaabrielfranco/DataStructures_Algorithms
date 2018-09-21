#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include "sort.h"

typedef std::chrono::high_resolution_clock Clock;

template <class T>
double mean(T A[], size_t n)
{
    double sum = 0;
    for (size_t i = 0; i < n; i++)
    {
        sum += A[i];
    }
    return sum / n;
}

template <class T>
double standart_deviation(T A[], size_t n, T mean)
{
    double sum = 0;
    for (size_t i = 0; i < n; i++)
    {
        sum += (A[i] - mean) * (A[i] - mean);
    }
    return sqrt(double(sum / n));
}

template <class T>
void make_copy(T A[], T B[], long n)
{
    for (size_t i = 0; i < n; i++)
    {
        B[i] = A[i];
    }
}

template <class T>
void benchmark(long A[], long B[], size_t n, size_t k_values[])
{
    for (size_t i = 0; i < 4; i++)
    {
        std::cout << "k = " << k_values[i] << std::endl;
        int64_t time_values[100];
        for (size_t j = 0; j < 100; j++)
        {
            make_copy(A, B, n);
            auto start = Clock::now();
            quick_sort(B, n, k_values[i]);
            auto end = Clock::now();

            time_values[j] =
                std::chrono::duration_cast<std::chrono::milliseconds>(end -
                                                                      start)
                    .count();
            // std::cout << time_values[j] << "ms\n";
        }
        long values_mean = mean(time_values, 100);
        long values_std = standart_deviation(time_values, 100, values_mean);
        printf("Mean: %lu  Standart Deviation: %lu\n", values_mean, values_std);
    }
}

int main(int argc, char** argv)
{
    if (argc > 1)
    {
        size_t n = strtol(argv[1], nullptr, 10);
        size_t k_values[4] = {100, 1000, 10000, 100000};
        long* A = (long*)malloc(n * sizeof(long));
        long* B = (long*)malloc(n * sizeof(long));
        for (size_t i = 0; i < n; i++)
        {
            scanf("%ld", &A[i]);
        }
        benchmark<long>(A, B, n, k_values);
        free(A);
        free(B);
    }
    else
    {
        std::cout << "Informe o tamanho do vetor\n";
    }
    return 0;
}