#ifndef MULTISET_H
#define MULTISET_H

template <class T>
class Multiset
{
   public:
    struct Node
    {
        T key;
        size_t num_ocurrences;
        Node* left;
        Node* rigth;
        Node* dad;

        Node()
        {
            this->left = nullptr;
            this->rigth = nullptr;
            this->dad = nullptr;
        }
    };

   private:
    Multiset<T>::Node* root;
    size_t length;

   public:
    Multiset()
    {
        this->root = nullptr;
        this->length = 0;
    }

    void insert(T value)
    {
        if (this->root == nullptr)
        {
            this->root = new Multiset<T>::Node;
            this->root->key = value;
            this->root->num_ocurrences = 1;
        }
        else
        {
            return;
            // search
            // Se achar, num_occurr++, senão, insere
        }
        this->length++;
    }

    void print(Multiset<T>::Node* cursor)
    {
        if (cursor == nullptr)
        {
            return;
        }

        for (int i = 0; i < cursor->num_ocurrences; i++)
        {
            printf("%d\n", cursor->key);
        }

        print(cursor->left);
        print(cursor->rigth);
    }

    Multiset<T>::Node* get_root()
    {
        return this->root;
    }

    size_t length()
    {
        return this->length;
    }
};
#endif