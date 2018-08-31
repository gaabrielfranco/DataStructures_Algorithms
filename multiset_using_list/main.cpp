#include <cstdio>
#include "Multiset.h"

int main()
{
    Multiset<int> multiset;
    multiset.insert(0);

    multiset.print();

    multiset.remove(0);

    multiset.print();

    return 0;
}