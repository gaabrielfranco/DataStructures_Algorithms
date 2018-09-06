#include <cstdio>
#include "Multiset.h"

int main()
{
    Multiset<int> multiset;
    // printf("%llu %llu\n", multiset.capacity(), multiset.length());
    multiset.insert(1);
    multiset.insert(0);
    multiset.insert(2);
    multiset.insert(1);
    multiset.insert(1);
    // printf("%llu %llu\n", multiset.capacity(), multiset.length());
    multiset.print();
    multiset.erase(1);
    multiset.print();
    return 0;
}