#include <iostream>
#include <stack>

using namespace std;

template <typename T>
class BSTNode {
public:
    T key;
    BSTNode<T> *left;
    BSTNode<T> *right;
    BSTNode<T> *parent;

    BSTNode(const T& key, BSTNode<T> *parent = nullptr) : key(key), left(nullptr), right(nullptr), parent(parent) {}

    ~BSTNode() {
        delete left;
        delete right;
    }

    void insert(const T& key) {
        if (key < this->key) {
            if (left == nullptr) {
                left = new BSTNode<T>(key, this);
            } else {
                left->insert(key);
            }
        } else if (key > this->key) {
            if (right == nullptr) {
                right = new BSTNode<T>(key, this);
            } else {
                right->insert(key);
            }
        }
    }

    void print() {
        if (left != nullptr) {
            left->print();
        }
        if (parent) {
            cout << "key: " << key << " parent: " << parent->key << ", " ;
        } else {
            cout << "key: " << key << ", ";
        }
        if (right != nullptr) {
            right->print();
        }
    }

    class iterator {
        BSTNode<T>* current_node;
        std::stack<BSTNode<T>*> node_stack;
    public:
        iterator(BSTNode<T>* root) {
            current_node = root;

            if (root) {
                while (current_node->left) {
                    current_node = current_node->left;
                }
            }
          }

        iterator& operator++() {
            if (current_node->right) {
                current_node = current_node->right;
                while (current_node->left) {
                    current_node = current_node->left;
                }
            } else {
                while (current_node->parent && current_node->parent->right == current_node) {
                    current_node = current_node->parent;
                }
                if (!current_node->parent) {
                    current_node = nullptr;
                    return *this;
                }
                current_node = current_node->parent;

            }
            return *this;
        }

        iterator operator++(int) {
            iterator reval = *this;

            ++(*this);
            return reval;
        }

        BSTNode<T>* operator*() {
            return current_node;
        }

        bool operator!=(iterator other) {
            return current_node != other.current_node;
        }
    };

    iterator begin() {
        return iterator(this);
    }

    iterator end() {
        return iterator(nullptr);
    }
};
