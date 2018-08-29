#ifndef TREE_H
#define TREE_H

template <class T>
class Tree
{
   public:
    Node<T>* root;

    Tree()
    {
        root = nullptr;
    }

    void insert(T value)
    {
        if (root == nullptr)
        {
            this->root = new Node<T>;
            this->root->key = value;
        }
        else
        {
            // search
            // Se achar, num_occurr++, senão, insere
        }
    }
};
#endif