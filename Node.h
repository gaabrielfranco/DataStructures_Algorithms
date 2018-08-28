#ifndef NODE_H
#define NODE_H

template <class T>
class Node
{
   public:
    T value;
    size_t num_ocurrences;
    Node* previous;
    Node* next;

    Node()
    {
        previous = nullptr;
        next = nullptr;
    }

    ~Node()
    {
        previous = nullptr;
        next = nullptr;
    }
};

#endif