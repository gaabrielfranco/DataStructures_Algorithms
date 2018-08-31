#ifndef MULTISET_H
#define MULTISET_H

#include <algorithm>

template <class T>
class Multiset
{
    struct Node
    {
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

    Multiset<T>::Node* head;
    Multiset<T>::Node* tail;
    size_t length;

   public:
    Multiset()
    {
        this->head = nullptr;
        this->tail = nullptr;
        this->length = 0;
    }

    ~Multiset()
    {
        for (auto it = this->head; it != nullptr;)
        {
            auto next = it->next;
            delete it;
            it = next;
        }
        this->length = 0;
    }

    void insert(T value)
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

        auto new_node = new Multiset<T>::Node;
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

        this->length++;
    }

    void erase(T value)
    {
        size_t num_elem = 0;

        for (auto it = this->head; it != nullptr;)
        {
            if (it->value == value)
            {
                if (it == this->head)
                {
                    if (it == this->tail)
                    {
                        // Conferir com o Jansen
                        num_elem = it->num_ocurrences;

                        delete it;

                        this->head = this->tail = nullptr;

                        break;
                    }

                    it->next->previous = nullptr;
                    this->head = it->next;
                    num_elem = it->num_ocurrences;

                    delete it;

                    break;
                }
                else if (it == this->tail)
                {
                    it->previous->next = nullptr;
                    this->tail = it->previous;
                    num_elem = it->num_ocurrences;

                    delete it;

                    break;
                }
                else
                {
                    it->previous->next = it->next;
                    it->next->previous = it->previous;
                    num_elem = it->num_ocurrences;

                    delete it;

                    break;
                }
            }
            it = it->next;
        }

        this->length -= num_elem;
    }

    void remove(T value)
    {
        for (auto it = this->head; it != nullptr;)
        {
            if (it->value == value)
            {
                if (it->num_ocurrences == 1)
                {
                    if (this->head == this->tail)
                    {
                        delete it;

                        this->head = this->tail = nullptr;
                    }
                    else
                    {
                        it->previous->next = it->next;
                        it->next->previous = it->previous;
                    }

                    delete it;
                }
                else
                {
                    it->num_ocurrences--;
                }

                this->length--;

                return;
            }
            it = it->next;
        }
    }

    const Multiset<T>::Node* begin() const
    {
        return this->head;
    }

    bool belongs_to(T value)
    {
        for (auto it = this->head; it != nullptr;)
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
        for (auto it = this->head; it != nullptr;)
        {
            if (it->value == value)
            {
                return it->num_ocurrences;
            }
            it = it->next;
        }

        return 0;
    }

    Multiset<T> union_multiset(const Multiset<T>& multiset)
    {
        Multiset<T> new_multiset;

        for (auto it = this->head; it != nullptr;)
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

        for (auto it = this->head; it != nullptr;)
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

        for (auto it = this->head; it != nullptr;)
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

    void print()
    {
        printf("{ ");
        for (auto it = this->head; it != nullptr;)
        {
            for (size_t i = 0; i < it->num_ocurrences; i++)
            {
                printf("%d ", it->value);
            }
            it = it->next;
        }
        puts("}");
    }
};
#endif