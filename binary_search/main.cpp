#include <iostream>
#include "binary_search.h"

int main()
{
    int v[5] = {1, 2, 3, 4, 5};

    std::cout << "Busca binaria recursiva no vetor {1, 2, 3, 4, 5}\n";
    std::cout << "Posicao do elemento 3: " << binary_search(v, 0, 5, 3)
              << std::endl;
    std::cout << "Posicao do elemento 2: " << binary_search(v, 0, 5, 2)
              << std::endl;
    std::cout << "Posicao do elemento 1: " << binary_search(v, 0, 5, 1)
              << std::endl;
    std::cout << "Posicao do elemento 4: " << binary_search(v, 0, 5, 4)
              << std::endl;
    std::cout << "Posicao do elemento 5: " << binary_search(v, 0, 5, 5)
              << std::endl;
    std::cout << "Posicao do elemento 8: ";
    auto result = binary_search(v, 0, 5, 8);
    result == ULLONG_MAX ? std::cout << "Nao existe\n\n"
                         : std::cout << result << std::endl
                                     << std::endl;

    std::cout << "Busca binaria iterativa no vetor {1, 2, 3, 4, 5}\n";
    std::cout << "Posicao do elemento 3: " << binary_search(v, 0, 5, 3)
              << std::endl;
    std::cout << "Posicao do elemento 2: " << binary_search(v, 0, 5, 2)
              << std::endl;
    std::cout << "Posicao do elemento 1: " << binary_search(v, 0, 5, 1)
              << std::endl;
    std::cout << "Posicao do elemento 4: " << binary_search(v, 0, 5, 4)
              << std::endl;
    std::cout << "Posicao do elemento 5: " << binary_search(v, 0, 5, 5)
              << std::endl;
    std::cout << "Posicao do elemento 8: ";
    result = binary_search(v, 0, 5, 8);
    result == ULLONG_MAX ? std::cout << "Nao existe\n"
                         : std::cout << result << std::endl;
    return 0;
}