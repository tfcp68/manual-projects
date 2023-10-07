#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <vector>

template <typename T>
class DoublyLinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;
        explicit Node(const T& data = T(), Node* next = nullptr, Node* prev = nullptr);
    };
    Node* head;
    Node* tail;
    int size;
    bool _validatePosition(int position);
    void _insertAfter(Node* current, Node* new_node);
public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void pushFront(const T& data);
    void pushBack(const T& data);
    void popFront();
    void popBack();
    void removeAtIndex(int pos);
    void removeByData(const T& data);
    bool find(const T& data);
    void insert(const T& data, int pos);
    void remove(Node* node);
    std::vector<T> tour();

    T getFront();
    T getBack();
    int getSize();
    bool isEmpty();
};

#include "dll.tpp"

#endif