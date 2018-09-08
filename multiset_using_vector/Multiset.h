#ifndef MULTISET_H
#define MULTISET_H

#include <cstdlib>
#include <iostream>
#include <algorithm>

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
            this->capacity = 1000;
            this->buffer = (T*)malloc(1000 * sizeof(T));
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

    /*Multiset(const Multiset& multiset)
    {
        multiset.vector->buffer = (T*)malloc(this->vector->capacity * sizeof(T));

        for(size_t i = 0; i < this->vector->length; i++)
        {
            multiset.vector->buffer[i] = this->vector->buffer[i];
        }

        multiset.vector->length = this->vector->length;
        multiset.vector->capacity = this->vector->capacity;
    }

    Multiset(Multiset&& multiset)
    {
        this->vector = multiset.vector;
        multiset.vector = nullptr;
    }

    Multiset& operator=(const Multiset& multiset)
    {
        multiset.vector->buffer = (T*)malloc(this->vector->capacity * sizeof(T));

        for(size_t i = 0; i < this->vector->length; i++)
        {
            multiset.vector->buffer[i] = this->vector->buffer[i];
        }

        multiset.vector->length = this->vector->length;
        multiset.vector->capacity = this->vector->capacity;

        return *this;
    }

    Multiset& operator=(Multiset&& multiset)
    {
        this->vector = multiset.vector;
        multiset.vector = nullptr;

        return *this;
    }*/

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
        else if (!this->vector->length)
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
        int left, mid, rigth;
        left = 0;
        rigth = this->vector->length - 1;
        while (left <= rigth)
        {
            mid = (left + rigth) / 2;
            if (this->vector->buffer[mid] == value)
                return mid;
            if (this->vector->buffer[mid] < value)
                left = mid + 1;
            else
                rigth = mid - 1;
        }
        exists = false;
        return 0;
    }

    void remove(T value)
    {
        bool exists = true;
        size_t pos = this->b_search(value, exists);
        std::cout << "Pos = " << pos << std::endl;

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
                if (i < 0)
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
                if (i < 0)
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
        }

        return upper_pos - lower_pos + 1;
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

        for(; i < this->vector->length && j < multiset.vector->length;)
        {
            if(this->vector->buffer[i] < multiset.vector->buffer[j])
            {
                new_multiset.insert(this->vector->buffer[i]);
                i++;
            }
            else
            {
                new_multiset.insert(multiset.vector->buffer[j]);
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
            for(; j < multiset.vector->length; j++)
            {
                new_multiset.insert(multiset.vector->buffer[j]);
            }
        }

        return new_multiset;
    }

    //Testar mais
    Multiset<T> intersection_multiset(const Multiset<T>& multiset)
    {
        Multiset<T> new_multiset;
        size_t lower = 0;
        bool exists;

        for(size_t i = 0; i < this->vector->length;)
        {
            lower = i;
            exists = true;

            while(this->vector->buffer[i] == this->vector->buffer[i+1])
            {
                i++;
            }

            size_t pos = multiset.b_search(this->vector->buffer[i], exists);

            if (exists)
            {
                size_t lower_pos = pos;
                size_t upper_pos = pos;

                for (size_t j = pos - 1;; j--)
                {
                    if (j < 0)
                    {
                        lower_pos = 0;
                        break;
                    }
                    else if (multiset.vector->buffer[pos] == multiset.vector->buffer[j])
                    {
                        lower_pos = j;
                    }
                    else
                    {
                        break;
                    }
                }

                for (size_t j = pos + 1; j < multiset.vector->length; j++)
                {
                    if (multiset.vector->buffer[pos] == multiset.vector->buffer[j])
                    {
                        upper_pos = j;
                    }
                    else
                    {
                        break;
                    }
                }

                auto num_ocurrences = std::min(i - lower + 1, upper_pos - lower_pos + 1);

                for (size_t j = 0; j < num_ocurrences; j++)
                {
                    new_multiset.insert(this->vector->buffer[i]);
                }
            }
            i++;
        }

        return new_multiset;
    }

    Multiset<T> difference_multiset(const Multiset<T>& multiset)
    {
        Multiset<T> new_multiset;
        
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