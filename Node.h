#ifndef NODE_H
#define NODE_H

template <class T>
class Node
{
    private:
        T value;
        T* previous;
        T* next;
    public:
        Node();
        ~Node();
        void set_value(T new_value);
        T get_value();
        void set_previous(T* new_previous);
        T* get_previous();
        void set_next(T* new_next);
        T* get_next();
};

#endif