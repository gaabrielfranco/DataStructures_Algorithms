#include <iostream>

template <class T>
class bst
{
   public:
    struct Node
    {
        T key;
        Node* left;
        Node* right;
        Node* parent;
        bool color;  // 0 black, 1 red

        Node()
        {
            this->left = nullptr;
            this->right = nullptr;
            this->parent = nullptr;
            this->color = 0;
        }
    };

   private:
    Node* root;
    size_t length;

   public:
    bst()
    {
        this->root = nullptr;
        this->length = 0;
    }

    Node* search(T key)
    {
        Node* it = this->root;

        for (; it != nullptr;)
        {
            if (key == it->key)
            {
                return it;
            }
            else if (key < it->key)
            {
                it = it->left;
            }
            else
            {
                it = it->right;
            }
        }

        return nullptr;
    }

    Node* max()
    {
        Node* it = this->root;

        for (; it->right != nullptr;)
        {
            it = it->right;
        }

        return it;
    }

    Node* min()
    {
        Node* it = this->root;

        for (; it->left != nullptr;)
        {
            it = it->left;
        }

        return it;
    }

    void insert(T key)
    {
        Node* it = this->root;
        Node* new_node = new Node;
        new_node->key = key;

        this->length++;
        if (it != nullptr)
        {
            for (;;)
            {
                if (key < it->key && it->left != nullptr)
                {
                    it = it->left;
                }
                else if (key < it->key)
                {
                    new_node->parent = it;
                    it->left = new_node;
                    return;
                }
                else if (it->right != nullptr)
                {
                    it = it->right;
                }
                else
                {
                    new_node->parent = it;
                    it->right = new_node;
                    return;
                }
            }
        }
        else
        {
            this->root = new_node;
        }
    }

    void remove(Node* node)
    {
        if (node != nullptr)
        {
            this->length--;

            if (node->right == nullptr && node->left == nullptr)
            {
                if (node->parent->key > node->key)
                {
                    node->parent->left = nullptr;
                }
                else
                {
                    node->parent->right = nullptr;
                }
                delete node;
            }
            else if (node->right == nullptr)
            {
                node->parent->right = node->left;
                delete node;
            }
            else if (node->left == nullptr)
            {
                node->parent->left = node->right;
                delete node;
            }
            else
            {
                Node* it = node->left;
                for (; it->right != nullptr;)
                {
                    it = it->right;
                }

                node->key = it->key;

                if (it->left != nullptr)
                {
                    it->left->parent = it->parent;
                    it->parent->right = it->left;
                }

                delete it;
            }
        }
    }

    void remove(T key)
    {
        Node* node = this->search(key);
        this->remove(node);
    }

    void remove_biggest()
    {
        Node* node = this->max();
        this->remove(node);
    }

    void print(Node* node)
    {
        if (node == nullptr)
        {
            return;
        }
        this->print(node->left);
        std::cout << node->key << " ";
        this->print(node->right);
    }

    void print()
    {
        this->print(this->root);
    }

    Node* get_root()
    {
        return this->root;
    }

    size_t get_length()
    {
        return this->length;
    }

    long long get_height(Node* node)
    {
        if (node == nullptr)
        {
            return -1;
        }
        return std::max(get_height(node->left), get_height(node->right)) + 1;
    }

    long long get_height()
    {
        return this->get_height(this->root);
    }

    size_t num_leafs(Node* node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        else if (node->left == nullptr && node->right == nullptr)
        {
            return 1;
        }
        return this->num_leafs(node->left) + this->num_leafs(node->right);
    }

    size_t num_leafs()
    {
        return this->num_leafs(this->root);
    }

    size_t num_internal_nodes()
    {
        return this->length - this->num_leafs(this->root);
    }

    void clear(Node* node)
    {
        if (node == nullptr)
        {
            return;
        }
        this->clear(node->left);
        this->clear(node->right);
        delete node;
    }

    void clear()
    {
        this->clear(this->root);
        this->length = 0;
    }
};