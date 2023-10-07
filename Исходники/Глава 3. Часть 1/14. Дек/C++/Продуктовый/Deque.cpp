#include <iostream>

#include "Deque.h"

using namespace std;

bool Deque::is_empty() {
	if (top == nullptr) return true;
	return false;
}

void Deque::push_back(int element) {
	Box* new_element = new Box(element);
	new_element->next = top;
	top = new_element;
	count += 1;
}

void Deque::push_front(int element) {
	Box* new_element = new Box(element);
	if (is_empty()) {
		new_element->next = top;
		top = new_element;
	} else {
		new_element->data = element;
		Box* curr_element = top;
		while (curr_element->next != end) {
			curr_element = curr_element->next;
		}
		curr_element->next = new_element;
	}
	count += 1;
}

int Deque::pop_back() {
	if (is_empty()) return -1;
	Box* front_element = top;
	top = front_element->next;
	count -= 1;
	return front_element->data;
}

int Deque::pop_front() {
	if (is_empty()) return -1;
	Box* curr_element = top;
	Box* prev_element = new Box();
	while (curr_element->next != end) {
		prev_element = curr_element;
		curr_element = curr_element->next;
	}
	prev_element->next = end;
	if (size() == 1) top = nullptr;
	count -= 1;
	return curr_element->data;
}

int Deque::size() {
	return count;
}