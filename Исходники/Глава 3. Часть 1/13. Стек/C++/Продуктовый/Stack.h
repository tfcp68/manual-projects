#ifndef STACK_H
#define STACK_H

#include <iostream>


template <typename T>
struct Node {
	T data;
	Node* next = nullptr;
	Node(T new_data) {
		data = new_data;
	}
};


template <typename T>
class Stack {
private:
	int count = 0;
	Node<T>* top = nullptr;
public:
	void push(T data);
	T pop();
	bool is_empty();
	int size();
};


/*Realization*/


template <typename T>
bool Stack<T>::is_empty() {
	if (top == nullptr) {
		return true;
	}
	return false;
}

template <typename T>
void Stack<T>::push(T data) {
	Node<T>* new_element = new Node<T>(data);
	new_element->next = top;
	top = new_element;
	count++;
}

template <typename T>
T Stack<T>::pop() {
	if (is_empty()) {
		return -1;
	}
	Node<T>* front_element = top;
	top = front_element->next;
	count--;
	return front_element->data;
}

template <typename T>
int Stack<T>::size() {
	return count;
}


#endif /*STACK_H*/
