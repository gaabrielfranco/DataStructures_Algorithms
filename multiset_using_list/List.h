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

    List()
    {
        this->head = nullptr;
        this->tail = nullptr;
    }

    ~List()
    {
        for (auto it = this->head; it != nullptr;)
        {
            auto next = it->next;
            delete it;
            it = next;
        }
    }

    void push_back(T value)
    {
        for (auto it = this->head; it != nullptr;)
        {
            if (it->value == value)
            {
                it->num_ocurrences++;
                return;
            }
            it = it->next;
        }

        auto new_node = new Node<T>;
        new_node->value = value;
        new_node->num_ocurrences = 1;

        if (this->head == nullptr && this->tail == nullptr)
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
    }

    int erase(T value)
    {
        for (auto it = this->head; it != nullptr;)
        {
            if (it->value == value)
            {
                if (it == this->head)
                {
                    it->next->previous = nullptr;
                    this->head = it->next;
                    size_t num_elem = it->num_ocurrences;

                    delete it;

                    return num_elem;
                }
                else if (it == this->tail)
                {
                    it->previous->next = nullptr;
                    this->tail = it->previous;
                    size_t num_elem = it->num_ocurrences;

                    delete it;

                    return num_elem;
                }
                else
                {
                    it->previous->next = it->next;
                    it->next->previous = it->previous;
                    size_t num_elem = it->num_ocurrences;

                    delete it;

                    return num_elem;
                }
            }
            it = it->next;
        }
        return 0;
    }

    void remove(T value)
    {
        for (auto it = this->head; it != nullptr;)
        {
            if (it->value == value)
            {
                if (it->num_ocurrences == 1)
                {
                    it->previous->next = it->next;
                    it->next->previous = it->previous;

                    delete it;
                }
                else
                {
                    it->num_ocurrences--;
                }

                return;
            }
            it = it->next;
        }
    }
};

#endif