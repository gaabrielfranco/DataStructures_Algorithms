#include <cstdio>
#include "Node.h"

int main()
{
    Node<int> node, node1, node2;
    int value, ant, prox;

    scanf("%d", &value);
    node.set_value(value);
    scanf("%d", &ant);
    scanf("%d", &prox);

    node1.set_value(ant);
    node2.set_value(prox);

    node.set_previous(node1);
    node.set_next(node2);

    printf("%d %d %d\n", node.get_value(), node.get_previous()->get_value(),
           node.get_next()->get_value());

    return 0;
}