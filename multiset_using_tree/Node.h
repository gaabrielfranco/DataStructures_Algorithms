#ifndef NODE_H
#define NODE_H

template <class T>
class Node
{
   public:
    T key;
    size_t num_ocurrences;
    Node<T>* left;
    Node<T>* rigth;
    Node<T>* dad;

    Node()
    {
        this->left = nullptr;
        this->rigth = nullptr;
        this->dad = nullptr;
    }

    ~Node()
    {
        this->left = nullptr;
        this->rigth = nullptr;
        this->dad = nullptr;
    }
};

#endif