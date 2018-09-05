#include <cstdio>
#include "Multiset.h"

int main()
{
    Multiset<int> multiset;
    multiset.insert(0);
    multiset.print(multiset.get_root());
    puts("Oi");
    return 0;
}