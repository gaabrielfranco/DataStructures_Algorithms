#include <cstdio>
#include "List.h"
#include "Multiset.h"
#include "Node.h"

int main()
{
    Multiset<int> multiset, m2;

    multiset.insert(0);
    multiset.insert(0);
    multiset.insert(1);
    multiset.insert(1);
    multiset.insert(1);

    m2.insert(0);
    m2.insert(2);
    m2.insert(3);

    printf("Tam = %zd\n", multiset.length);

    for (auto it = multiset.begin(); it != nullptr;)
    {
        printf("%d %zd\n", it->value, it->num_ocurrences);
        it = it->next;
    }

    puts("");

    printf("Tam = %zd\n", m2.length);

    for (auto it = m2.begin(); it != nullptr;)
    {
        printf("%d %zd\n", it->value, it->num_ocurrences);
        it = it->next;
    }
    puts("");

    printf("%d\n", multiset.belongs_to(0));
    printf("%d\n", multiset.belongs_to(3));

    puts("");

    printf("%zd\n", multiset.frequency(0));
    printf("%zd\n", multiset.frequency(1));

    puts("");

    multiset.erase(1);

    printf("Tam = %zd\n", multiset.length);

    for (auto it = multiset.begin(); it != nullptr;)
    {
        printf("%d %zd\n", it->value, it->num_ocurrences);
        it = it->next;
    }

    auto m3 = multiset.union_multiset(m2);

    puts("");

    printf("Tam = %zd\n", m3.length);

    for (auto it = m3.begin(); it != nullptr;)
    {
        printf("%d %zd\n", it->value, it->num_ocurrences);
        it = it->next;
    }

    puts("");

    auto m4 = multiset.intersection_multiset(m2);

    puts("");

    printf("Tam = %zd\n", m4.length);

    for (auto it = m4.begin(); it != nullptr;)
    {
        printf("%d %zd\n", it->value, it->num_ocurrences);
        it = it->next;
    }

    multiset.insert(2);
    multiset.insert(3);
    auto m5 = multiset.difference_multiset(m2);

    puts("");

    printf("Tam = %zd\n", m5.length);

    for (auto it = m5.begin(); it != nullptr;)
    {
        printf("%d %zd\n", it->value, it->num_ocurrences);
        it = it->next;
    }

    return 0;
}