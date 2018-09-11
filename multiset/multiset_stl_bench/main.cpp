#include <algorithm>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <set>
#include <vector>

#define NUM_ELEMENTS 100000

typedef std::chrono::high_resolution_clock Clock;

int main(int argc, char** argv)
{
    std::multiset<int> m1, m2;
    std::vector<int> m3;
    if (!strcmp("--bench1", argv[1]))
    {
        // Insert in M1
        auto start = Clock::now();
        for (int i = 0; i < NUM_ELEMENTS; i++)
        {
            m1.insert(i);
        }

        auto end = Clock::now();
        std::cout << "Insertion duration in M1: ";
        std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(
                         end - start)
                         .count();
        std::cout << "ms\n";

        // Insert in M2
        start = Clock::now();
        for (int i = 0; i < NUM_ELEMENTS; i++)
        {
            m2.insert(i);
        }

        end = Clock::now();
        std::cout << "Insertion duration in M2: ";
        std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(
                         end - start)
                         .count();
        std::cout << "ms\n";

        // Union
        start = Clock::now();

        std::set_union(m1.begin(), m1.end(), m2.begin(), m2.end(),
                       std::back_inserter(m3));
        end = Clock::now();
        std::cout << "Union duration: ";
        std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(
                         end - start)
                         .count();
        std::cout << "ms\n";

        // Insersection
        start = Clock::now();

        std::set_intersection(m1.begin(), m1.end(), m2.begin(), m2.end(),
                              m3.begin());
        end = Clock::now();
        std::cout << "Insersection duration: ";
        std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(
                         end - start)
                         .count();
        std::cout << "ms\n";

        // Difference
        start = Clock::now();
        std::set_difference(m1.begin(), m1.end(), m2.begin(), m2.end(),
                            std::back_inserter(m3));
        end = Clock::now();
        std::cout << "Difference duration: ";
        std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(
                         end - start)
                         .count();
        std::cout << "ms\n";

        // Cleaning M1
        start = Clock::now();
        for (int i = 0; i < NUM_ELEMENTS; i++)
        {
            m1.erase(i);
        }

        end = Clock::now();
        std::cout << "Duration of Cleaning of M2: ";
        std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end -
                                                                          start)
                         .count();
        std::cout << "ns\n";

        // Cleaning M2
        start = Clock::now();
        m2.clear();

        end = Clock::now();
        std::cout << "Duration of Cleaning of M2: ";
        std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end -
                                                                          start)
                         .count();
        std::cout << "ns\n";
    }
    else if (!strcmp("--bench2", argv[1]))
    {
        // Insert in M1
        auto start = Clock::now();
        for (int i = 0; i < NUM_ELEMENTS; i++)
        {
            m1.insert(0);
        }

        auto end = Clock::now();
        std::cout << "Insertion duration in M1: ";
        std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end -
                                                                          start)
                         .count();
        std::cout << "ns\n";

        // Insert in M2
        start = Clock::now();
        for (int i = 0; i < NUM_ELEMENTS; i++)
        {
            m2.insert(0);
        }

        end = Clock::now();
        std::cout << "Insertion duration in M2: ";
        std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end -
                                                                          start)
                         .count();
        std::cout << "ns\n";

        // Union
        start = Clock::now();

        std::set_union(m1.begin(), m1.end(), m2.begin(), m2.end(),
                       std::back_inserter(m3));
        end = Clock::now();
        std::cout << "Union duration: ";
        std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(
                         end - start)
                         .count();
        std::cout << "ms\n";

        // Insersection
        start = Clock::now();

        std::set_intersection(m1.begin(), m1.end(), m2.begin(), m2.end(),
                              m3.begin());
        end = Clock::now();
        std::cout << "Insersection duration: ";
        std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(
                         end - start)
                         .count();
        std::cout << "ms\n";

        // Difference
        start = Clock::now();
        std::set_difference(m1.begin(), m1.end(), m2.begin(), m2.end(),
                            std::back_inserter(m3));
        end = Clock::now();
        std::cout << "Difference duration: ";
        std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(
                         end - start)
                         .count();
        std::cout << "ms\n";

        // Cleaning M1
        start = Clock::now();
        for (int i = 0; i < NUM_ELEMENTS; i++)
        {
            m1.erase(0);
        }

        end = Clock::now();
        std::cout << "Duration of Cleaning of M2: ";
        std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end -
                                                                          start)
                         .count();
        std::cout << "ns\n";

        // Cleaning M2
        start = Clock::now();
        m2.clear();

        end = Clock::now();
        std::cout << "Duration of Cleaning of M2: ";
        std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end -
                                                                          start)
                         .count();
        std::cout << "ns\n";
    }
    else if (!strcmp("--bench3", argv[1]))
    {
        int element;
        int m1_elements[NUM_ELEMENTS];
        int m2_elements[NUM_ELEMENTS];
        srand(time(NULL));

        // Insert in M1
        auto start = Clock::now();
        for (int i = 0; i < NUM_ELEMENTS; i++)
        {
            element = rand() % NUM_ELEMENTS;
            m1_elements[i] = element;
            m1.insert(element);
        }

        auto end = Clock::now();
        std::cout << "Insertion duration in M1: ";
        std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(
                         end - start)
                         .count();
        std::cout << "ms\n";

        // Insert in M2
        start = Clock::now();
        for (int i = 0; i < NUM_ELEMENTS; i++)
        {
            element = rand() % NUM_ELEMENTS;
            m2_elements[i] = element;
            m2.insert(element);
        }

        end = Clock::now();
        std::cout << "Insertion duration in M2: ";
        std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(
                         end - start)
                         .count();
        std::cout << "ms\n";

        // Union
        start = Clock::now();

        std::set_union(m1.begin(), m1.end(), m2.begin(), m2.end(),
                       std::back_inserter(m3));
        end = Clock::now();
        std::cout << "Union duration: ";
        std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(
                         end - start)
                         .count();
        std::cout << "ms\n";

        // Insersection
        start = Clock::now();

        std::set_intersection(m1.begin(), m1.end(), m2.begin(), m2.end(),
                              m3.begin());
        end = Clock::now();
        std::cout << "Insersection duration: ";
        std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(
                         end - start)
                         .count();
        std::cout << "ms\n";

        // Difference
        start = Clock::now();
        std::set_difference(m1.begin(), m1.end(), m2.begin(), m2.end(),
                            std::back_inserter(m3));
        end = Clock::now();
        std::cout << "Difference duration: ";
        std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(
                         end - start)
                         .count();
        std::cout << "ms\n";

        // Cleaning M1
        start = Clock::now();
        for (int i = 0; i < NUM_ELEMENTS; i++)
        {
            m1.erase(m1_elements[i]);
        }

        end = Clock::now();
        std::cout << "Duration of Cleaning of M2: ";
        std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end -
                                                                          start)
                         .count();
        std::cout << "ns\n";

        // Cleaning M2
        start = Clock::now();
        m2.clear();

        end = Clock::now();
        std::cout << "Duration of Cleaning of M2: ";
        std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end -
                                                                          start)
                         .count();
        std::cout << "ns\n";
    }
    else
    {
        std::cout << "Multiset run options:\n\n";
        std::cout << "defaut: to run a simple test\n";
        std::cout << "--bench1 to run the benchmark 1\n";
        std::cout << "--bench2 to run the benchmark 2\n";
        std::cout << "--bench3 to run the benchmark 3\n";
        std::cout << "--h to help\n";
    }

    return 0;
}
