#include "dll.h"
#include <iostream>

using namespace std;

template <typename T>
DoublyLinkedList<T>::Node::Node(const T& data, Node* next, Node* prev) {
    this->data = data;
    this->next = next;
    this->prev = prev;
}



template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}



template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    while (head != nullptr) {
        popFront();
    }
}



template <typename T>
bool DoublyLinkedList<T>::_validatePosition(int position) {
    return position >= 0 && position <= size;
}



template <typename T>
void DoublyLinkedList<T>::_insertAfter(Node* current, Node* new_node) {
    new_node->prev = current;
    new_node->next = current->next;

    if (current->next != nullptr) {
        current->next->prev = new_node;
    } else {
        tail = new_node;
    }

    current->next = new_node;
    size++;
}



template <typename T>
void DoublyLinkedList<T>::remove(Node* node) {
    if (node == head) return popFront();

    if (node == tail) return popBack();

    node->prev->next = node->next;
    node->next->prev = node->prev;
    delete node;
    size--;
}



template <typename T>
void DoublyLinkedList<T>::removeAtIndex(int pos) {
    if (!_validatePosition(pos)) return;

    if (pos == 0) return popFront();

    Node* current = head;
    for (int i = 0; i < pos; i++) {
        current = current->next;
    }

    return remove(current);
}



template <typename T>
void DoublyLinkedList<T>::removeByData(const T& data) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == data) {
            return remove(current);
        } else {
            current = current->next;
        }
    }
}



template <typename T>
void DoublyLinkedList<T>::pushFront(const T& data) {
    if (head == nullptr) {
        head = new Node(data);
        tail = head;
    } else {
        head->prev = new Node(data, head);
        head = head->prev;
    }
    size++;
}



template <typename T>
void DoublyLinkedList<T>::pushBack(const T& data) {
    if (tail == nullptr) {
        tail = new Node(data);
        head = tail;
    } else {
        tail->next = new Node(data, nullptr, tail);
        tail = tail->next;
    }
    size++;
}



template <typename T>
void DoublyLinkedList<T>::insert(const T& data, int pos) {
    if (!_validatePosition(pos)) return;

    if (pos == 0) return pushFront(data);

    if (pos == size) return pushBack(data);

    Node* current = head;
    while (current != nullptr) {
        current = current->next;
    }

    Node* new_node = new Node(data);
    return _insertAfter(current, new_node);
}



template <typename T>
void DoublyLinkedList<T>::popFront() {
    if (head != nullptr) {
        Node* temp = head->next;
        delete head;
        head = temp;

        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }

        size--;
    }
}



template <typename T>
void DoublyLinkedList<T>::popBack() {
    if (tail != nullptr) {
        Node *temp = tail->prev;
        delete tail;
        tail = temp;

        if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }

        size--;
    }
}



template <typename T>
bool DoublyLinkedList<T>::find(const T& data) {
    for (Node* current = head; current != nullptr; current = current->next) {
        if(current->data == data){
            return true;
        }
    }

    return false;
}



template <typename T>
vector<T> DoublyLinkedList<T>::tour() {
    vector<T> arr;

    if (size == 0) return {};

    for (Node* current = head; current != nullptr; current = current->next) {
        arr.push_back(current->data);
    }

    for (Node* current = tail->prev; current != nullptr; current = current->prev) {
        arr.push_back(current->data);
    }

    return arr;
}



template <typename T>
T DoublyLinkedList<T>::getBack() {
    return tail->data;
}



template <typename T>
T DoublyLinkedList<T>::getFront() {
    return head->data;
}



template <typename T>
int DoublyLinkedList<T>::getSize() {
    return size;
}



template <typename T>
bool DoublyLinkedList<T>::isEmpty() {
    return size == 0;
}