#ifndef MULTISET_H
#define MULTISET_H

#include <algorithm>
#include <cstdlib>
#include <iostream>

template <class T>
class Multiset
{
   public:
    struct Vector
    {
        size_t length;
        size_t capacity;
        T* buffer;

        Vector()
        {
            this->length = 0;
            this->capacity = 1024;
            this->buffer = (T*)malloc(1024 * sizeof(T));
        }

        ~Vector()
        {
            free(this->buffer);
        }
    };

   private:
    Multiset<T>::Vector* vector;

   public:
    Multiset()
    {
        this->vector = new Multiset<T>::Vector;
    }

    ~Multiset()
    {
        delete this->vector;
    }

    void insert(T value)
    {
        if (this->vector->capacity == this->vector->length)
        {
            this->vector->capacity *= 2;
            this->vector->buffer = (T*)realloc(
                this->vector->buffer, this->vector->capacity * sizeof(T));
        }

        if (!this->vector->length)
        {
            this->vector->buffer[0] = value;
            this->vector->length++;
        }
        else
        {
            for (size_t i = 0; i < this->vector->length; i++)
            {
                if (this->vector->buffer[i] > value)
                {
                    for (size_t j = this->vector->length - 1; j >= i; j--)
                    {
                        this->vector->buffer[j + 1] = this->vector->buffer[j];

                        if (j == 0)
                        {
                            break;
                        }
                    }
                    this->vector->buffer[i] = value;
                    this->vector->length++;
                    return;
                }
            }
            this->vector->buffer[this->vector->length] = value;
            this->vector->length++;
        }
    }

    size_t b_search(T value, bool& exists) const
    {
        int left, mid, right;
        left = 0;
        right = this->vector->length - 1;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (this->vector->buffer[mid] == value)
                return mid;
            if (this->vector->buffer[mid] < value)
                left = mid + 1;
            else
                right = mid - 1;
        }
        exists = false;
        return 0;
    }

    void remove(T value)
    {
        bool exists = true;
        size_t pos = this->b_search(value, exists);

        if (exists)
        {
            for (size_t i = pos; i < this->vector->length; i++)
            {
                this->vector->buffer[i] = this->vector->buffer[i + 1];
            }
            this->vector->length--;
        }
    }

    void erase(T value)
    {
        bool exists = true;
        size_t pos = this->b_search(value, exists);
        size_t removed = 0;
        size_t lower_pos = pos;
        size_t upper_pos = pos;

        if (exists)
        {
            for (size_t i = pos - 1;; i--)
            {
                if (i <= 0)
                {
                    lower_pos = 0;
                    break;
                }
                else if (value == this->vector->buffer[i])
                {
                    lower_pos = i;
                }
                else
                {
                    break;
                }
            }

            for (size_t i = pos + 1; i < this->vector->length; i++)
            {
                if (value == this->vector->buffer[i])
                {
                    upper_pos = i;
                }
                else
                {
                    break;
                }
            }

            removed = upper_pos - lower_pos + 1;

            for (size_t i = upper_pos + 1, j = lower_pos;
                 i < this->vector->length; i++, j++)
            {
                this->vector->buffer[j] = this->vector->buffer[i];
            }

            this->vector->length -= removed;
        }
    }

    bool has(T value)
    {
        bool exists = true;
        this->b_search(value, exists);
        return exists;
    }

    size_t frequency(T value)
    {
        bool exists = true;
        size_t pos = this->b_search(value, exists);
        size_t lower_pos = pos;
        size_t upper_pos = pos;

        if (exists)
        {
            for (size_t i = pos - 1;; i--)
            {
                if (i <= 0)
                {
                    lower_pos = 0;
                    break;
                }
                else if (value == this->vector->buffer[i])
                {
                    lower_pos = i;
                }
                else
                {
                    break;
                }
            }

            for (size_t i = pos + 1; i < this->vector->length; i++)
            {
                if (value == this->vector->buffer[i])
                {
                    upper_pos = i;
                }
                else
                {
                    break;
                }
            }

            return upper_pos - lower_pos + 1;
        }
        else
        {
            return 0;
        }
    }

    void print()
    {
        printf("{ ");
        for (size_t i = 0; i < this->vector->length; i++)
        {
            std::cout << this->vector->buffer[i] << " ";
        }
        puts("} ");
    }

    Multiset<T> union_multiset(const Multiset<T>& multiset)
    {
        Multiset<T> new_multiset;

        size_t i = 0;
        size_t j = 0;

        for (; i < this->vector->length && j < multiset.vector->length;)
        {
            if (this->vector->buffer[i] < multiset.vector->buffer[j])
            {
                new_multiset.insert(this->vector->buffer[i]);
                i++;
            }
            else if (this->vector->buffer[i] > multiset.vector->buffer[j])
            {
                new_multiset.insert(multiset.vector->buffer[j]);
                j++;
            }
            else
            {
                new_multiset.insert(multiset.vector->buffer[j]);
                i++;
                j++;
            }
        }

        if (i < this->vector->length)
        {
            for (; i < this->vector->length; i++)
            {
                new_multiset.insert(this->vector->buffer[i]);
            }
        }
        else if (j < multiset.vector->length)
        {
            for (; j < multiset.vector->length; j++)
            {
                new_multiset.insert(multiset.vector->buffer[j]);
            }
        }

        return new_multiset;
    }

    Multiset<T> intersection_multiset(const Multiset<T>& multiset)
    {
        Multiset<T> new_multiset;

        size_t i = 0;
        size_t j = 0;

        for (; i < this->vector->length && j < multiset.vector->length;)
        {
            if (this->vector->buffer[i] < multiset.vector->buffer[j])
            {
                i++;
            }
            else if (this->vector->buffer[i] > multiset.vector->buffer[j])
            {
                j++;
            }
            else
            {
                new_multiset.insert(multiset.vector->buffer[j]);
                i++;
                j++;
            }
        }

        return new_multiset;
    }

    Multiset<T> difference_multiset(const Multiset<T>& multiset)
    {
        Multiset<T> new_multiset;

        size_t i = 0;
        size_t j = 0;

        for (; i < this->vector->length && j < multiset.vector->length;)
        {
            if (this->vector->buffer[i] < multiset.vector->buffer[j])
            {
                new_multiset.insert(this->vector->buffer[i]);
                i++;
            }
            else if (this->vector->buffer[i] > multiset.vector->buffer[j])
            {
                j++;
            }
            else
            {
                i++;
                j++;
            }
        }

        for (; i < this->vector->length; i++)
        {
            new_multiset.insert(multiset.vector->buffer[i]);
        }

        return new_multiset;
    }

    size_t length()
    {
        return this->vector->length;
    }

    size_t capacity()
    {
        return this->vector->capacity;
    }

    T* get_buffer()
    {
        return this->vector->buffer;
    }
};
#endif