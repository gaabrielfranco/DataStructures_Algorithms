#include "Node.cpp"
#include <cstdio>

int main()
{
    Node<int> node;
    int value, ant, prox;

    scanf("%d", &value);
    node.set_value(value);
    scanf("%d", &ant);
    scanf("%d", &prox);
    node.set_previous(&ant);
    node.set_next(&prox);

    printf("%d %d %d\n", node.get_value(), *(node.get_previous()), *(node.get_next()));

    return 0;
}