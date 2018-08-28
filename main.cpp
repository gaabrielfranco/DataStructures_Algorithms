#include <cstdio>
#include "List.h"
#include "Node.h"

int main()
{
    List<int> list;

    list.push_back(10);
    list.push_back(20);

    printf("%d %d\n", list.head->value, list.tail->value);
    return 0;
}