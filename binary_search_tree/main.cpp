#include <iostream>
#include "bst.h"

int main()
{
    bst<int> tree;
    tree.insert(3);
    tree.insert(1);
    tree.insert(2);
    tree.insert(20);
    tree.insert(21);
    tree.insert(10);
    tree.insert(9);
    tree.insert(12);
    tree.insert(11);
    tree.insert(14);
    tree.insert(13);

    bst<int>::Node* result = tree.search(9);
    std::cout << "Existe o elemento 9 na arvore ? ";
    result != nullptr ? puts("Sim") : puts("Nao");

    result = tree.search(55);
    std::cout << "Existe o elemento 55 na arvore ? ";
    result != nullptr ? puts("Sim") : puts("Nao");

    puts("\nArvore em ordem: ");

    tree.print();

    puts("");

    std::cout << "Tamanho da arvore = " << tree.get_length() << std::endl;

    std::cout << "Altura da arvore = " << tree.get_height() << std::endl;

    std::cout << "Numero de folhas da arvore = " << tree.num_leafs()
              << std::endl;

    std::cout << "Numero de nos internos da arvore = "
              << tree.num_internal_nodes() << std::endl;

    puts("\nRemovendo o elemento 20...");

    tree.remove(20);

    puts("\nArvore em ordem: ");

    tree.print(tree.get_root());

    puts("");

    std::cout << "Tamanho da arvore = " << tree.get_length() << std::endl;

    std::cout << "Altura da arvore = " << tree.get_height() << std::endl;

    std::cout << "Numero de folhas da arvore = " << tree.num_leafs()
              << std::endl;

    std::cout << "Numero de nos internos da arvore = "
              << tree.num_internal_nodes() << std::endl;

    puts("\nLimpando a arvore...");
    tree.clear();

    std::cout << "Tamanho da arvore = " << tree.get_length() << std::endl;

    return 0;
}