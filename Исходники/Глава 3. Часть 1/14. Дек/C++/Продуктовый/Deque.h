#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>


template <typename T>
struct Node {
	T data;
	Node* next = nullptr;
	Node(T new_data = T()) {
		data = new_data;
	}
};


template <typename T>
class Deque {
private:
	int count = 0;
	Node<T>* end = nullptr;
	Node<T>* top = nullptr;
public:
	void push_front(T data);
	void push_back(T data);
	T pop_front();
	T pop_back();
	bool is_empty();
	int size();
};


/*Realization*/


template <typename T>
bool Deque<T>::is_empty() {
	if (top == nullptr) {
		return true;
	}
	return false;
}


template <typename T>
void Deque<T>::push_back(T data) {
	Node<T>* new_element = new Node<T>(data);
	new_element->next = top;
	top = new_element;
	count++;
}

template <typename T>
void Deque<T>::push_front(T data) {
	Node<T>* new_element = new Node<T>(data);
	if (is_empty()) {
		new_element->next = top;
		top = new_element;
	}
	else {
		new_element->data = data;
		Node<T>* curr_element = top;
		while (curr_element->next != end) {
			curr_element = curr_element->next;
		}
		curr_element->next = new_element;
	}
	count++;
}

template <typename T>
T Deque<T>::pop_back() {
	if (is_empty()) {
		return -1;
	}
	Node<T>* front_element = top;
	top = front_element->next;
	count--;
	return front_element->data;
}

template <typename T>
T Deque<T>::pop_front() {
	if (is_empty()) {
		return -1;
	}
	Node<T>* curr_element = top;
	Node<T>* prev_element = new Node<T>();
	while (curr_element->next != end) {
		prev_element = curr_element;
		curr_element = curr_element->next;
	}
	prev_element->next = end;
	if (size() == 1) {
		top = nullptr;
	}
	count--;
	return curr_element->data;
}

template <typename T>
int Deque<T>::size() {
	return count;
}


#endif /*DEQUE_H*/
