#ifndef MULTISET_H
#define MULTISET_H

#include <algorithm>

template <class T>
class Multiset
{
   public:
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
    };

   private:
    Multiset<T>::Node* head;
    Multiset<T>::Node* tail;
    size_t length;

   public:
    class Iterator
    {
        Multiset<T>::Node* pointer;

       public:
        Iterator(Multiset<T>::Node* pointer) : pointer(pointer)
        {
        }
        bool operator!=(const Iterator& it)
        {
            return this->pointer != it.pointer;
        }

        Iterator& operator++()
        {
            this->pointer = this->pointer->next;
            return *this;
        }

        Node& operator*()
        {
            return *(this->pointer);
        }
    };

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

    Multiset(const Multiset& multiset)
    {
        Multiset<T>::Node* cursor;

        for (auto& it : multiset)
        {
            auto node = new Multiset<T>::Node;
            node->value = it.value;
            node->num_ocurrences = it.num_ocurrences;

            if (&it == multiset.head)
            {
                this->head = node;
            }
            else
            {
                cursor->next = node;
                node->previous = cursor;
            }

            cursor = node;
        }

        this->tail = cursor;
    }

    Multiset(Multiset&& multiset)
    {
        this->head = multiset.head;
        this->tail = multiset.tail;
        multiset.head = nullptr;
        multiset.tail = nullptr;
    }

    Multiset& operator=(const Multiset& multiset)
    {
        Multiset<T>::Node* cursor;

        for (auto& it : multiset)
        {
            auto node = new Multiset<T>::Node;
            node->value = it.value;
            node->num_ocurrences = it.num_ocurrences;

            if (&it == multiset.head)
            {
                this->head = node;
            }
            else
            {
                cursor->next = node;
                node->previous = cursor;
            }

            cursor = node;
        }

        this->tail = cursor;

        return *this;
    }

    Multiset& operator=(Multiset&& multiset)
    {
        this->head = multiset.head;
        this->tail = multiset.tail;
        multiset.head = nullptr;
        multiset.tail = nullptr;

        return *this;
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

        if (!this->length)
        {
            this->head = new_node;
            this->tail = new_node;
            this->length++;

            return;
        }

        Multiset<T>::Node* greater = nullptr;

        for (auto& it : *this)
        {
            if (it.value > value)
            {
                greater = &it;
                break;
            }
        }

        if (!greater)
        {
            this->tail->next = new_node;
            new_node->previous = this->tail;
            this->tail = new_node;
        }
        else if (greater == this->head)
        {
            this->head->previous = new_node;
            new_node->next = this->head;
            this->head = new_node;
        }
        else
        {
            new_node->next = greater;
            new_node->previous = greater->previous;

            greater->previous->next = new_node;
            greater->previous = new_node;
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

    Multiset<T>::Iterator begin() const
    {
        return Multiset<T>::Iterator(this->head);
    }

    Multiset<T>::Iterator end() const
    {
        return Multiset<T>::Iterator(this->tail->next);
    }

    bool has(T value)
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

        for (auto it = multiset.head; it != nullptr;)
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
            for (auto it2 = multiset.head; it2 != nullptr;)
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
            for (auto it2 = multiset.head; it2 != nullptr;)
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

    Multiset<T>::Node* get_head()
    {
        return this->head;
    }

    Multiset<T>::Node* get_tail()
    {
        return this->tail;
    }

    Multiset<T>::Node& operator[](T value)
    {
        for (auto& it : *this)
        {
            if (it.value == value)
            {
                return it;
            }
        }

        throw "Value doesn't exists.";
    }

    size_t length()
    {
        return this->length;
    }
};
#endif