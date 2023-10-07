
template <typename T>
bool Stack<T>::is_empty() {
	if (top == nullptr) {
		return true;
	}
	return false;
}

template <typename T>
void Stack<T>::push(T data) {
	Box<T>* new_element = new Box<T>(data);
	new_element->next = top;
	top = new_element;
	count++;
}

template <typename T>
T Stack<T>::pop() {
	if (is_empty()) { 
		return -1; 
	} 
	Box<T>* front_element = top;
	top = front_element->next;
	count--;
	return front_element->data;
}

template <typename T>
int Stack<T>::size() {
	return count;
}