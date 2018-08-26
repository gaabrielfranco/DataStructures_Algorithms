#ifndef NODE_H
#define NODE_H

template <class T>
class Node
{
   private:
    T value;
    Node* previous;
    Node* next;

   public:
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

    void set_value(T new_value)
    {
        this->value = new_value;
    }

    T get_value()
    {
        return value;
    }

    void set_previous(Node& new_previous)
    {
        this->previous = &new_previous;
    }

    Node* get_previous()
    {
        return this->previous;
    }

    void set_next(Node& new_next)
    {
        this->next = &new_next;
    }

    Node* get_next()
    {
        return this->next;
    }
};

#endif