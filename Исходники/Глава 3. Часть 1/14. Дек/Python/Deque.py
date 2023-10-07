class Node:
    def __init__(self, data=None, next=None, prev=None):
        self.next = next
        self.data = data
        self.prev = prev


class Deque:
    def __init__(self):
        self._end = Node()
        self._top = Node(next=self._end)
        self._size = 0

    def _push_first_element(self, data):
        firs_node = Node(data, self._end, self._top)
        self._top.next = firs_node
        self._end.prev = firs_node

    def push_front(self, data):
        if self.is_empty():
            self._push_first_element(data)
        else:
            next_element = self._top.next
            self._top.next = Node(data, next_element, self._top)
            next_element.prev = self._top.next
        self._size += 1

    def pop_back(self):
        if self.is_empty():
            return -1
        prev_end_element = self._end.prev
        before_prev_end = prev_end_element.prev
        self._end.prev = before_prev_end
        before_prev_end.next = self._end
        self._size -= 1
        return prev_end_element.data

    def push_back(self, data):
        if self.is_empty():
            self._push_first_element(data)
        else:
            prev_element = self._end.prev
            self._end.prev = Node(data, self._end, prev_element)
            prev_element.next = self._end.prev
        self._size += 1

    def pop_front(self):
        if self.is_empty():
            return -1
        prev_top_element = self._top.next
        after_prev_top = prev_top_element.next
        self._top.next = after_prev_top
        after_prev_top.prev = self._top
        self._size -= 1
        return prev_top_element.data

    def is_empty(self):
        if (self._top.next == self._end
                or self._end.prev == self._top):
            return True
        return False

    def size(self):
        return self._size




