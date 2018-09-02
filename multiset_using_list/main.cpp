#include <cstdio>
#include <utility>
#include "Multiset.h"

int main()
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

    printf("0 pertence ao Multiset 2 ? %s\n\n", m2.has(0) ? "True" : "False");

    printf("0 aparece no Multiset 1 %d vezes\n\n", multiset.frequency(0));

    printf("1 aparece no Multiset 2 %d vezes\n\n", m2.frequency(1));

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

    return 0;
}