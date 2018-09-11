#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "Multiset.h"
#define NUM_ELEMENTS 100000

typedef std::chrono::high_resolution_clock Clock;

int main(int argc, char** argv)
{
    if (argc == 1)
    {
        Multiset<int> multiset, m2;
        multiset.insert(0);
        multiset.insert(0);
        multiset.insert(0);
        multiset.insert(1);
        multiset.insert(1);
        multiset.insert(2);
        multiset.insert(5);
        multiset.insert(3);

        m2.insert(1);
        m2.insert(2);
        m2.insert(4);
        m2.insert(5);

        puts("Multiset 1");
        multiset.print();
        puts("");

        puts("Multiset 2");
        m2.print();
        puts("");

        printf("0 pertence ao Multiset 1 ? %s\n\n",
               multiset.has(0) ? "True" : "False");

        printf("0 pertence ao Multiset 2 ? %s\n\n",
               m2.has(0) ? "True" : "False");

        printf("0 aparece no Multiset 1 %lu vezes\n\n", multiset.frequency(0));

        printf("1 aparece no Multiset 2 %lu vezes\n\n", m2.frequency(1));

        puts("Multiset 1 uniao com o Multiset 2");
        auto m3 = multiset.union_multiset(m2);
        m3.print();
        puts("");

        puts("Multiset 1 intersecao com o Multiset 2");
        auto m4 = multiset.intersection_multiset(m2);
        m4.print();
        puts("");

        puts("Multiset 1 diferenca com o Multiset 2");
        auto m5 = multiset.difference_multiset(m2);
        m5.print();
        puts("");

        puts("Apagando uma ocorrencia do elemento 0 do Multiset 1...");
        multiset.remove(0);
        multiset.print();
        puts("");

        puts("Apagando todas as ocorrencias do elemento 1 do Multiset 1...");
        multiset.erase(1);
        multiset.print();
        puts("");
    }
    else if (!strcmp("--bench1", argv[1]))
    {
        Multiset<int> m1, m2;

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
        auto m3 = m1.union_multiset(m2);
        end = Clock::now();
        std::cout << "Union duration: ";
        std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(
                         end - start)
                         .count();
        std::cout << "ms\n";

        // Insersection
        start = Clock::now();
        auto m4 = m1.union_multiset(m2);
        end = Clock::now();
        std::cout << "Insersection duration: ";
        std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(
                         end - start)
                         .count();
        std::cout << "ms\n";

        // Difference
        start = Clock::now();
        auto m5 = m1.union_multiset(m2);
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
        std::cout << "Duration of Cleaning of M1: ";
        std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end -
                                                                          start)
                         .count();
        std::cout << "ns\n";

        // Cleaning M2
        start = Clock::now();
        for (int i = 0; i < NUM_ELEMENTS; i++)
        {
            m2.remove(i);
        }

        end = Clock::now();
        std::cout << "Duration of Cleaning of M2: ";
        std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end -
                                                                          start)
                         .count();
        std::cout << "ns\n";
    }
    else if (!strcmp("--bench2", argv[1]))
    {
        Multiset<int> m1, m2;

        // Insert in M1
        auto start = Clock::now();
        for (int i = 0; i < NUM_ELEMENTS; i++)
        {
            m1.insert(0);
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
            m2.insert(0);
        }

        end = Clock::now();
        std::cout << "Insertion duration in M2: ";
        std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(
                         end - start)
                         .count();
        std::cout << "ms\n";

        // Union
        start = Clock::now();
        auto m3 = m1.union_multiset(m2);
        end = Clock::now();
        std::cout << "Union duration: ";
        std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(
                         end - start)
                         .count();
        std::cout << "ms\n";

        // Insersection
        start = Clock::now();
        auto m4 = m1.union_multiset(m2);
        end = Clock::now();
        std::cout << "Insersection duration: ";
        std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(
                         end - start)
                         .count();
        std::cout << "ms\n";

        // Difference
        start = Clock::now();
        auto m5 = m1.union_multiset(m2);
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
        std::cout << "Duration of Cleaning of M1: ";
        std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end -
                                                                          start)
                         .count();
        std::cout << "ns\n";

        // Cleaning M2
        start = Clock::now();
        for (int i = 0; i < NUM_ELEMENTS; i++)
        {
            m2.remove(0);
        }

        end = Clock::now();
        std::cout << "Duration of Cleaning of M2: ";
        std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end -
                                                                          start)
                         .count();
        std::cout << "ns\n";
    }
    else if (!strcmp("--bench3", argv[1]))
    {
        Multiset<int> m1, m2;
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
        auto m3 = m1.union_multiset(m2);
        end = Clock::now();
        std::cout << "Union duration: ";
        std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(
                         end - start)
                         .count();
        std::cout << "ms\n";

        // Insersection
        start = Clock::now();
        auto m4 = m1.union_multiset(m2);
        end = Clock::now();
        std::cout << "Insersection duration: ";
        std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(
                         end - start)
                         .count();
        std::cout << "ms\n";

        // Difference
        start = Clock::now();
        auto m5 = m1.union_multiset(m2);
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
        std::cout << "Duration of Cleaning of M1: ";
        std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end -
                                                                          start)
                         .count();
        std::cout << "ns\n";

        // Cleaning M2
        start = Clock::now();
        for (int i = 0; i < NUM_ELEMENTS; i++)
        {
            m2.remove(m2_elements[i]);
        }

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