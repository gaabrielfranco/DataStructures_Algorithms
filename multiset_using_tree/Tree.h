#ifndef TREE_H
#define TREE_H

template <class T>
class Tree
{
    struct Node
    {
       public:
        T key;
        size_t num_ocurrences;
        Node<T>* left;
        Node<T>* rigth;
        Node<T>* dad;

        Node()
        {
            this->left = nullptr;
            this->rigth = nullptr;
            this->dad = nullptr;
        }

        ~Node()
        {
            this->left = nullptr;
            this->rigth = nullptr;
            this->dad = nullptr;
        }
    };
    Tree<T>::Node* root;

   public:
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
            return;
            // search
            // Se achar, num_occurr++, senão, insere
        }
    }
};
#endif