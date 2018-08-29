#ifndef MULTISET_H
#define MULTISET_H

#include <algorithm>
#include "List.h"

template <class T>
class Multiset
{
   public:
    List<T>* multiset;
    size_t length;

    Multiset()
    {
        this->multiset = new List<T>;
        this->length = 0;
    }

    ~Multiset()
    {
        delete this->multiset;
    }

    Node<T>* begin() const
    {
        return multiset->head;
    }

    void insert(T value)
    {
        this->multiset->push_back(value);
        this->length++;
    }

    bool belongs_to(T value)
    {
        for (auto it = this->multiset->head; it != nullptr;)
        {
            if (it->value == value)
            {
                return true;
            }
            it = it->next;
        }

        return false;
    }

    size_t frequency(T value)
    {
        for (auto it = this->multiset->head; it != nullptr;)
        {
            if (it->value == value)
            {
                return it->num_ocurrences;
            }
            it = it->next;
        }

        return 0;
    }

    void erase(T value)
    {
        this->length -= this->multiset->erase(value);
    }

    void remove(T value)
    {
        this->multiset->remove(value);
        this->length--;
    }

    Multiset<T> union_multiset(const Multiset<T>& multiset)
    {
        Multiset<T> new_multiset;

        for (auto it = this->multiset->head; it != nullptr;)
        {
            for (size_t i = 0; i < it->num_ocurrences; i++)
            {
                new_multiset.insert(it->value);
            }
            it = it->next;
        }

        for (auto it = multiset.begin(); it != nullptr;)
        {
            for (size_t i = 0; i < it->num_ocurrences; i++)
            {
                new_multiset.insert(it->value);
            }
            it = it->next;
        }

        return new_multiset;
    }

    Multiset<T> intersection_multiset(const Multiset<T>& multiset)
    {
        Multiset<T> new_multiset;

        for (auto it = this->multiset->head; it != nullptr;)
        {
            for (auto it2 = multiset.begin(); it2 != nullptr;)
            {
                if (it->value == it2->value)
                {
                    size_t num_elem =
                        std::min(it->num_ocurrences, it2->num_ocurrences);

                    for (size_t i = 0; i < num_elem; i++)
                    {
                        new_multiset.insert(it->value);
                    }

                    break;
                }
                it2 = it2->next;
            }
            it = it->next;
        }

        return new_multiset;
    }

    Multiset<T> difference_multiset(const Multiset<T>& multiset)
    {
        Multiset<T> new_multiset;
        bool match = false;

        for (auto it = this->multiset->head; it != nullptr;)
        {
            for (auto it2 = multiset.begin(); it2 != nullptr;)
            {
                if (it->value == it2->value)
                {
                    if (it->num_ocurrences > it2->num_ocurrences)
                    {
                        size_t num_elem =
                            it->num_ocurrences - it2->num_ocurrences;

                        for (size_t i = 0; i < num_elem; i++)
                        {
                            new_multiset.insert(it->value);
                        }
                    }
                    match = true;
                    break;
                }
                it2 = it2->next;
            }

            if (!match)
            {
                for (size_t i = 0; i < it->num_ocurrences; i++)
                {
                    new_multiset.insert(it->value);
                }
            }

            it = it->next;
            match = false;
        }

        return new_multiset;
    }
};
#endif