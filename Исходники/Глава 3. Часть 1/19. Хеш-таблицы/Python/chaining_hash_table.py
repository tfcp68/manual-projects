from collections import deque
from typing import Hashable


class ChainingHashTable:
    def __init__(self,
                 default_capacity=10,
                 max_load_factor=0.7,
                 resize_factor=2):
        self._size = 0
        self._table = [deque() for _ in range(default_capacity)]
        self._max_load_factor = max_load_factor
        self._resize_factor = resize_factor

    def __len__(self):
        return self._size

    def __contains__(self, value):
        index = self._hash(value)
        return value in self._table[index]

    def __iter__(self):
        for bucket in self._table:
            for item in bucket:
                yield item

    def __eq__(self, other):
        if len(self) != len(other):
            return False
        for item in self:
            if item not in other:
                return False
        return True

    def load_factor(self) -> float:
        return self._size / len(self._table)

    def add(self, value: Hashable):
        if self.load_factor() > self._max_load_factor:
            self._resize()
        index = self._hash(value)
        for i, item in enumerate(self._table[index]):
            if item == value:
                self._table[index][i] = value
                return
        self._table[index].append(value)
        self._size += 1

    def remove(self, value: Hashable) -> bool:
        index = self._hash(value)
        if value not in self._table[index]:
            return False
        self._table[index].remove(value)
        self._size -= 1
        return True

    def _hash(self, item) -> int:
        return hash(item) % len(self._table)

    def _resize(self):
        new_size = int(len(self._table) * self._resize_factor)
        new_table = [deque() for _ in range(new_size)]
        for bucket in self._table:
            for item in bucket:
                index = hash(item) % new_size
                new_table[index].append(item)
        self._table = new_table
