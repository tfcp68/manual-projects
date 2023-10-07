#include "C_list.h"
#include <iostream>
#include <algorithm>

using namespace std;

template<typename elem_type>
typename LIST<elem_type>::Node *LIST<elem_type>::Iterator::operator->() {
    return m_ptr;
}

template<typename elem_type>
typename LIST<elem_type>::Iterator *LIST<elem_type>::Iterator::operator+(int other) {
    while (other) {
        m_ptr = m_ptr->next;
        other--;
    }
    return this;
}

template<typename elem_type>
typename LIST<elem_type>::Iterator *LIST<elem_type>::Iterator::operator-(int other) {
    while (other) {
        m_ptr = m_ptr->prev;
        other--;
    }
    return this;
}

template<typename elem_type>
elem_type LIST<elem_type>::Iterator::operator*() { return m_ptr->value; }

template<typename elem_type>
typename LIST<elem_type>::Iterator *LIST<elem_type>::Iterator::operator++() {m_ptr = m_ptr->next; return this; }

template<typename elem_type>
typename LIST<elem_type>::Iterator *LIST<elem_type>::Iterator::operator--()  {m_ptr = m_ptr->prev; return this; }

template<typename elem_type>
const typename LIST<elem_type>::Iterator LIST<elem_type>::Iterator::operator++(int)  {
    Node* temp = m_ptr;
    m_ptr = m_ptr->next;
    return Iterator(temp);
}

template<typename elem_type>
const typename LIST<elem_type>::Iterator LIST<elem_type>::Iterator::operator--(int)  {
    Node* temp = m_ptr;
//    if(m_ptr == nullptr) {
//        return Iterator(last);
//    }
    m_ptr = m_ptr->prev;
    return Iterator(temp);
}

template<typename elem_type>
bool LIST<elem_type>::Iterator::operator!=(const LIST::Iterator &other)  {return m_ptr != other.m_ptr;}

template<typename elem_type>
bool LIST<elem_type>::Iterator::operator==(const LIST::Iterator &other)  {return m_ptr == other.m_ptr;}

template<typename elem_type>
typename LIST<elem_type>::Iterator LIST<elem_type>::begin()  {return Iterator(first);}

template<typename elem_type>
typename LIST<elem_type>::Iterator LIST<elem_type>::end()  {return Iterator(nullptr);}

template<typename elem_type>
elem_type& LIST<elem_type>::operator[](int n) const  {
    Node* curr = first;
    while (n > 0) {
        curr = curr->next;
        n--;
    }
    return curr->value;
}

template<typename elem_type>
LIST<elem_type> &LIST<elem_type>::operator=(std::vector<elem_type> &vec) {
    while(count_size) {
        pop_back();
    }
    this->count_size = 0;
    this->first = nullptr;
    this->last = nullptr;
    for(auto it = vec.begin(); it != vec.end(); it++) {
        push_back(*it);
    }
}

template<typename elem_type>
LIST<elem_type>::Node::Node(elem_type value, Node* next, Node* prev) {
    this->value = value;
    this->next = next;
    this->prev = prev;
}

template<typename elem_type>
LIST<elem_type>::Node::~Node() {
    this->next = nullptr;
    this->prev = nullptr;
}

template<typename elem_type>
LIST<elem_type>::LIST() {
    this->count_size = 0;
    this->first = nullptr;
    this->last = nullptr;
}

template<typename elem_type>
LIST<elem_type>::LIST(std::vector<elem_type> &vec) {
    this->count_size = 0;
    this->first = nullptr;
    this->last = nullptr;
    for(auto it = vec.begin(); it != vec.end(); it++) {
        push_back(*it);
    }
}

//идти от головы до хвоста и удалять элементы
template<typename elem_type>
LIST<elem_type>::~LIST() {
    while(count_size) {
        pop_back();
    }
}

template<typename elem_type>
void LIST<elem_type>::push_front(elem_type &x) {
    if(!count_size) {
        auto node = new Node(x, nullptr, nullptr);
        last = node;
        first = node;
    }
    else {
        auto node = new Node(x, first, nullptr);
        node->next->prev = node;
        first = node;
    }
    count_size++;
}

template<typename elem_type>
void LIST<elem_type>::push_front(elem_type &&x) {
    if(!count_size) {
        auto node = new Node(x, nullptr, nullptr);
        last = node;
        first = node;
    }
    else {
        auto node = new Node(x, first, nullptr);
        node->next->prev = node;
        first = node;
    }
    count_size++;
}

template<typename elem_type>
void LIST<elem_type>::push_back(elem_type &x) {
    if(!count_size) {
        auto node = new Node(x, nullptr, nullptr);
        last = node;
        first = node;
    }
    else {
        auto node = new Node(x, nullptr, last);
        node->prev->next = node;
        last = node;
    }
    count_size++;
}

template<typename elem_type>
void LIST<elem_type>::push_back(elem_type &&x) {
    if(!count_size) {
        auto node = new Node(x, nullptr, nullptr);
        last = node;
        first = node;
    }
    else {
        auto node = new Node(x, nullptr, last);
        node->prev->next = node;
        last = node;
    }
    count_size++;
}

template<typename elem_type>
void LIST<elem_type>::pop_front() {
    if(count_size == 0) {
        return;
    }
    else if(count_size == 1) {
        delete first;
        count_size--;
    }
    else {
        auto elem = first->next;
        elem->prev = nullptr;
        delete first;
        first = elem;
        count_size--;
    }
}

template<typename elem_type>
void LIST<elem_type>::pop_back() {
    if(count_size == 0) {
        return;
    }
    else if(count_size == 1) {
        delete first;
        count_size--;
    }
    else {
        auto elem = last->prev;
        elem->next = nullptr;
        delete last;
        last = elem;
        count_size--;
    }
}

template<typename elem_type>
int LIST<elem_type>::size() {
    return count_size;
}

template<typename elem_type>
elem_type& LIST<elem_type>::front() {
    return first->value;
}

template<typename elem_type>
elem_type& LIST<elem_type>::back() {
    return last->value;
}

template<typename elem_type>
bool LIST<elem_type>::empty() {
    if(count_size == 0) return true;
    return false;
}

template<typename elem_type>
void LIST<elem_type>::insert(LIST::Iterator pos, elem_type &x) {
    if(pos == begin()) {
        push_front(x);
    }
    else if(pos == end()) {
        push_back(x);
    }
    else {
        auto new_elem = new Node(x, nullptr, nullptr);
        auto pos_l = pos->prev;
        auto pos_r = pos_l->next;

        pos_l->next = new_elem;
        pos_r->prev = new_elem;
        new_elem->next = pos_r;
        new_elem->prev = pos_l;
        count_size++;
    }
}

template<typename elem_type>
void LIST<elem_type>::insert(LIST::Iterator pos, elem_type &&x) {
    if(pos == begin()) {
        push_front(x);
    }
    else if(pos == end()) {
        push_back(x);
    }
    else {
        auto new_elem = new Node(x, nullptr, nullptr);
        auto pos_l = pos->prev;
        auto pos_r = pos_l->next;

        pos_l->next = new_elem;
        pos_r->prev = new_elem;
        new_elem->next = pos_r;
        new_elem->prev = pos_l;
        count_size++;
    }
}

template<typename elem_type>
void LIST<elem_type>::erase(Iterator pos) {
    if(pos == begin()) {
        pop_front();
    }
    else if(pos == end()) {
        pop_back();
    }
    else {
        auto pos_r = pos->next;
        auto pos_l = pos->prev;

        delete pos_l->next;
        pos_l->next = pos_r;
        pos_r->prev = pos_l;
        count_size--;
    }
}

template<typename elem_type>
void LIST<elem_type>::erase(Iterator pos_l, Iterator pos_r) {
    if(pos_l->prev == nullptr) {
        while(pos_l != pos_r) {
            pos_l = pos_l->next;
            pop_front();
        }
        pop_front();
    }
    else if(pos_r == nullptr) {
        pos_r = last;
        while(pos_r != pos_l) {
            pos_r = pos_r->prev;
            pop_back();
        }
        pop_back();
    }
    else {
        auto elem_l = pos_l->prev;
        auto elem_r = pos_r->next;
        while(pos_l != pos_r) {
            pos_l = pos_l->next;
            delete pos_l->prev;
            count_size--;
        }
        delete elem_r->prev;
        count_size--;
        elem_l->next = elem_r;
        elem_r->prev = elem_l;
    }
}
