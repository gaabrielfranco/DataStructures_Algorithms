#include <cstdio>
#include "Multiset.h"

int main()
{
    Multiset<int> multiset, multiset_2;
    // printf("%llu %llu\n", multiset.capacity(), multiset.length());
    multiset.insert(1);
    multiset.insert(0);
    multiset.insert(2);
    multiset.insert(1);
    multiset.insert(1);
    // printf("%llu %llu\n", multiset.capacity(), multiset.length());
    multiset.print();
    multiset.erase(1);
    puts("");
    multiset.print();

    multiset_2.insert(1);
    multiset_2.insert(0);
    multiset_2.insert(2);
    multiset_2.insert(1);
    multiset_2.insert(1);
    multiset_2.print();

    puts("");
    auto m3 = multiset.intersection_multiset(multiset_2);
    m3.print();

    return 0;
}