#include "Node.h"

template <class T>
Node<T>::Node()
{
    value = -1;
    previous = nullptr;
    next = nullptr;
}

template <class T>
Node<T>::~Node()
{
    value = -1;
    previous = nullptr;
    next = nullptr;
}

template <class T>
void Node<T>::set_value(T new_value)
{
    this->value = new_value;
}
template <class T>
T Node<T>::get_value()
{
    return value;
}
template <class T>
void Node<T>::set_previous(T* new_previous)
{
    previous = new_previous;
}
template <class T>
T* Node<T>::get_previous()
{
    return previous;
}
template <class T>
void Node<T>::set_next(T* new_next)
{
    next = new_next;
}
template <class T>
T* Node<T>::get_next()
{
    return next;
}