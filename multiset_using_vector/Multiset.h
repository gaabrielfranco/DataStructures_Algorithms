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
   class Iterator
    {
        Multiset<T>::Vector* pointer;

       public:
        Iterator(Multiset<T>::Vector* pointer) : pointer(pointer)
        {
        }
        bool operator!=(const Iterator& it)
        {
            return this->pointer != it.pointer;
        }

        Iterator& operator++()
        {
            this->pointer->buffer++;
            return *this;
        }

        Node& operator*()
        {
            return *(this->pointer);
        }
    };
    
    Multiset()
    {
        this->vector = new Multiset<T>::Vector;
    }

    void insert(T value)
    {
        if(this->vector->capacity == this->vector->length)
        {
            //realloc e inserir
        }
        else
        {
            for(size_t i = 0; i < this->vector->length; i++)
            {
                if(this->vector->buffer[i] > value)
                {
                    // inserir aqui e shiftar
                    //não precisa shiftar aqui
                    if (i == this->vector->length - 1)
                    {
                        this->vector->buffer[i] = value;
                    }
                    else
                    {
                        for(size_t j = this->vector->length - 1; j >= i; j--)
                        {
                            this->vector->buffer[j+1] = this->vector->buffer[j];
                        }
                    }
                }
            }
        }
    }

    size_t length()
    {
        return this->vector->length;
    }
};
#endif