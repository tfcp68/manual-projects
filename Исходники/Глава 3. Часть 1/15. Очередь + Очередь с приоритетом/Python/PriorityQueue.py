from math import inf


class Node:
    def __init__(self, data=None, priority=None, next=None, prev=None):
        self.next = next
        self.data = data
        self.prev = prev
        self.priority = priority


class Element:
    def __init__(self, data, priority):
        self.data = data
        self.priority = priority


class PriorityQueue:
    def __init__(self):
        self._end = Node(priority=-inf)
        self._top = Node(priority=+inf, next=self._end)
        self._size = 0

    def _push_first_element(self, element: Element):
        firs_node = Node(element.data, element.priority,
                         self._end, self._top)
        self._top.next = firs_node
        self._end.prev = firs_node

    def push(self, new_element: Element):
        self._size += 1
        if self.is_empty():
            self._push_first_element(new_element)
        else:
            curr_element = self._top.next
            while True:
                prev_curr = curr_element.prev
                if new_element.priority >= curr_element.priority:
                    new_element = Node(new_element.data, new_element.priority,
                                       curr_element, prev_curr)
                    prev_curr.next = new_element
                    curr_element.prev = new_element
                    return
                curr_element = curr_element.next

    def pop(self):
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
        return self._size# queue = PriorityQueue()
# queue.push(Element(1, 1))
# queue.push(Element(3, 3))
# queue.push(Element(5, 5))
# queue.push(Element(2, 2))
# queue.push(Element(4, 4))



# print(queue.pop())
# print(queue.pop())
# print(queue.pop())
# print(queue.pop())
# print(queue.pop())
# print(queue.pop())