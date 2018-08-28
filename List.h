#ifndef LIST_H
#define LIST_H

#include <cassert>
#include "Node.h"

template <class T>
class List
{
   public:
    Node<T>* head;
    Node<T>* tail;
    size_t length;

    List()
    {
        this->head = nullptr;
        this->tail = nullptr;
        this->length = 0;
    }

    void push_back(T value)
    {
        auto new_node = new Node<T>;
        new_node->value = value;

        if (!this->length)
        {
            this->head = new_node;
            this->tail = new_node;
        }
        else
        {
            this->tail->next = new_node;
            new_node->previous = this->tail;
            this->tail = new_node;
        }

        this->length++;
    }

    void insert(T value, size_t position)
    {
        assert(position <= length);

        auto new_node = new Node<T>;
        new_node->value = value;

        if (position == 0)
        {
            new_node->next = this->head;
            this->head->previous = new_node;
            this->head = new_node;
        }
        else if (position == this->length)
        {
            new_node->previous = this->tail;
            this->tail->next = new_node;
            this->tail = new_node;
        }
        /*
        Iterar a lista
        else
        {

        }
        */
    }
};

#endif