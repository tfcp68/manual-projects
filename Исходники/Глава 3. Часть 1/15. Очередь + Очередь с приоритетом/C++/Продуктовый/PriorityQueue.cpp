#include <iostream>

#include "PriorityQueue.h"

using namespace std;


bool PriorityQueue::is_empty() {
	if (top == nullptr) return true;
	return false;
}

void PriorityQueue::push(Element element) {
	Box* new_element = new Box(element.priority, element.data);
	count += 1;
	if (is_empty()) {
		new_element->next = top;
		top = new_element;
		return;
	}
	Box* curr_element = top;
	while (true) {
		if (new_element->priority >= curr_element->priority) {
			new_element->next = curr_element->next;
			curr_element->next = new_element;
			return;
		}
		curr_element = curr_element->next;
		if (curr_element == nullptr) {
			new_element->next = top;
			top = new_element;
			return;
		}
	}
}


int PriorityQueue::pop() {
	if (is_empty()) return -1;
	Box* curr_element = top;
	Box* prev_element = new Box();
	while (curr_element->next != nullptr) {
		prev_element = curr_element;
		curr_element = curr_element->next;
	}
	prev_element->next = nullptr;
	if (size() == 1) top = nullptr;
	count -= 1;
	return curr_element->data;
}

int PriorityQueue::size() {
	return count;
}