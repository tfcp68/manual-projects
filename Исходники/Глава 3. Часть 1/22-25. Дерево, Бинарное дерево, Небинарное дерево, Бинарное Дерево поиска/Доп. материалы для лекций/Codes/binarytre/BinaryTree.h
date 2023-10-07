#include <stdlib.h>
#include <iostream>
#include "vector"
using namespace std;

template<class T>
class Node {
public:
    T value;
    Node* left;
    Node* right;

    Node(T value) {
        this->value = value;
        left = NULL;
        right = NULL;
    }
};


template<class T>
class BinaryTree {
private:
    void add_node_privat(int value, Node<T>* node) {
        if (value < node->value) {
            if (node->left == NULL) {
                node->left = new Node<T>(value);
            } else {
                add_node_privat(value, node->left);
            }
        } else {
            if (node->right == NULL) {
                node->right = new Node<T>(value);
            } else {
                add_node_privat(value, node->right);
            }
        }
    }

    Node<T>* delete_node_privat(int value, Node<T>* node) {
        if (node == NULL) {
            return node;
        }

        if (value == node->value) {
            if (node->left == NULL) {
                return node->right;
            } else if (node->right == NULL) {
                return node->left;
            } else {
                Node<T>* temp_node = node->right;

                while (temp_node->left != NULL) {
                    temp_node = temp_node->left;
                }

                node->value = temp_node->value;
                node->right = delete_node_privat(node->value, node->right);
            }
        } else if (value < node->value) {
            node->left = delete_node_privat(value, node->left);
        } else {
            node->right = delete_node_privat(value, node->right);
        }

        return node;
    }

    Node<T>* find_node_privat(int value, Node<T>* node) {
        if (node != NULL) {
            if (value == node->value) {
                return node;
            } else if (value < node->value) {
                return find_node_privat(value, node->left);
            } else {
                return find_node_privat(value, node->right);
            }
        } else {
            return NULL;
        }
    }

    void tree_traversal_privat(Node<T>* node) {
        if (node != NULL) {
            tree_traversal_privat(node->left);
            list.push_back(node->value);
            tree_traversal_privat(node->right);
        }
    }
public:
    vector<int> list;
    Node<T>* root;
    BinaryTree() {
        root = NULL;
    }

    void add_node(int value) {
        if (root == NULL) {
            root = new Node<T>(value);
        } else {
            add_node_privat(value, root);
        }
    }

    void delete_node(int value) {
        if (root != NULL) {
            root = delete_node_privat(value, root);
        }
    }

    void tree_traversal() {
        list.clear();
        if (root != NULL) {
            tree_traversal_privat(root);
        }
    }


    bool find_node(int value) {
        if (root != NULL) {
            if (find_node_privat(value, root) != NULL){
                return true;
            }

        } else {
            return false;
        }
    }
};
