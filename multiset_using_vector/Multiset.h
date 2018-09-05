#ifndef MULTISET_H
#define MULTISET_H

#include <cstdlib>

template <class T>
class Multiset
{
   public:
    class Vector
    {
        size_t length;
        size_t capacity;
        T* buffer;

        Vector()
        {
            this->length = 0;
            this->capacity = 100;
            this->buffer = (T*) malloc(100 * sizeof(T));
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

    void insert(T value)
    {
        if(this->vector->capacity == this->vector->length)
        {
            //realloc
        }
        else
        {
            //inserir ordenado
        }
    }

    size_t length()
    {
        return this->vector->length;
    }
};
#endif