#ifndef C_LIST_H
#define C_LIST_H
#pragma once
#include <algorithm>
#include <memory>
#include <iterator>
#include <vector>

template<typename elem_type>
class LIST {
    struct Node {
        elem_type value;
        Node* next;
        Node* prev;

        Node(elem_type value, Node* next, Node* prev);
        ~Node();
    };
    int count_size = 0;
    Node* first;
    Node* last;


public:
    class Iterator {
        Node* m_ptr;

    public:
        Iterator(Node* ptr) : m_ptr(ptr) {}
        Node* operator->();
        elem_type operator*();
        Iterator* operator++();
        Iterator* operator+(int other);
        Iterator* operator-(int other);
        Iterator* operator--();
        const Iterator operator++(int);
        const Iterator operator--(int);
        bool operator!=(const Iterator& other);
        bool operator==(const Iterator& other);
    };

    elem_type& operator[](int n) const;
    LIST& operator=(std::vector<elem_type>& vec);

    void push_front(elem_type &x);
    void push_front(elem_type &&x);
    void push_back(elem_type &x);
    void push_back(elem_type &&x);
    void pop_front();
    void pop_back();
    elem_type& front();
    elem_type& back();
    int size();
    bool empty();

    void insert(Iterator pos, elem_type &x);
    void insert(Iterator pos, elem_type &&x);

    void erase(Iterator pos);
    void erase(Iterator pos_l, Iterator pos_r);

    Iterator begin();
    Iterator end();



    LIST();
    LIST(std::vector<elem_type>& vec);
    ~LIST();
};



#include "C_list.tpp"
#endif