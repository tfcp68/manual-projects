class Node:
    def __init__(self, data=None, next=None):
        self.next = next
        self.data = data


class Stack:
    def __init__(self):
        self._end = Node()
        self._top = Node(next=self._end)
        self._size = 0

    def push(self, data):
        old_element = self._top.next
        self._top.next = Node(data, old_element)
        self._size += 1

    def pop(self):
        if self.is_empty():
            return -1
        first_element = self._top.next
        self._top.next = first_element.next
        self._size -= 1
        return first_element.data

    def is_empty(self):
        if self._top.next == self._end:
            return True
        return False

    def peek(self):
        if not self.is_empty():
            last_element = self._top.next
            return last_element.data
        return self._end.data

    def size(self):
        return self._size



