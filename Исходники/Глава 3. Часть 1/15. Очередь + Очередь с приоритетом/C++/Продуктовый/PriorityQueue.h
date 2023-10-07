#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <iostream>
#include <limits>


template <typename T>
struct Element {
	T data;
	int priority;
	Element(int new_priority, T new_data) {
		data = new_data;
		priority = new_priority;
	}
};


template <typename T>
struct Node {
	T data;
	int priority;
	Node* next;
	Node* prev;
	Node(int new_priority = -INFINITY, T new_data = T(), 
		 Node* new_next = nullptr, Node* new_prev = nullptr) {
		data = new_data;
		priority = new_priority;
		next = new_next;
		prev = new_prev;
	}
};


template <typename T>
class PriorityQueue {
private:
	int count = 0;
	Node<T>* top = new Node<T>();
	Node<T>* end = new Node<T>();
public:
	void push(Element<T> data);
	T pop();
	bool is_empty();
	int size();
};


/*Realization*/


template <typename T>
bool PriorityQueue<T>::is_empty() {
	if (top->next == nullptr || end->prev == nullptr) {
		return true;
	}
	return false;
}


template <typename T>
void PriorityQueue<T>::push(Element<T> element) {
	count++;
	if (is_empty()) {
		Node<T>* new_element = new Node<T>(element.priority, element.data, end, top);
		top->next = new_element;
		end->prev = new_element;
		return;
	}
	Node<T>* curr_element = top->next;
	while (true) {
		Node<T>* prev_curr = curr_element->prev;
		if (element.priority >= curr_element->priority) {
			Node<T>* new_element = new Node<T>(element.priority, element.data, 
											   curr_element, prev_curr);
			prev_curr->next = new_element;
			curr_element->prev = new_element;
			return;
		}
		curr_element = curr_element->next;
	}
}


template <typename T>
T PriorityQueue<T>::pop() {
	if (is_empty()) {
		return -1;
	}
	Node<T>* prev_top = top->next;
	Node<T>* after_prev_top = prev_top->next;
	top->next = after_prev_top;
	if (after_prev_top != nullptr) {
		after_prev_top->prev = top;
	}
	if (count > 0) {
		count--;
	}
	return prev_top->data;
}


template <typename T>
int PriorityQueue<T>::size() {
	return count;
}

#endif /*PRIORITY_QUEUE_H*/

