from enum import Enum
from typing import Hashable, Any
from dataclasses import dataclass


def linear_probing(index, iteration, step=1):
    return index + step * iteration


def quadratic_probing(index, iteration, step=1):
    return index + ((step * iteration) ** 2)


@dataclass
class OpenAddressingHashTableBucket:
    class State(Enum):
        EMPTY = 0
        DELETED = 1
        OCCUPIED = 2

    value: Hashable = None
    state: State = State.EMPTY

    def __bool__(self):
        return self.state == self.State.OCCUPIED

    def set(self, value):
        self.value = value
        self.state = self.State.OCCUPIED

    def clear(self):
        self.value = None
        self.state = self.State.DELETED

    def can_set(self) -> bool:
        return self.state in (self.State.DELETED, self.State.EMPTY)


class OpenAddressingHashTable:
    Bucket = OpenAddressingHashTableBucket

    def __init__(self,
                 default_capacity=10,
                 max_load_factor=0.7,
                 resize_factor=2,
                 probing_function=quadratic_probing):
        self._size = 0
        self._table = [self.Bucket() for _ in range(default_capacity)]
        self._max_load_factor = max_load_factor
        self._resize_factor = resize_factor
        self._probing_function = probing_function

    def __len__(self):
        return self._size

    def __contains__(self, value):
        index = self._find_index(value)
        if index >= len(self._table):
            return False
        bucket = self._table[index]
        return bool(bucket)

    def __iter__(self):
        for bucket in self._table:
            if bucket:
                yield bucket.value

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
        if self._add_existing(value):
            return
        if self.load_factor() > self._max_load_factor:
            self._resize()
        index = self._find_index(value, for_add=True)
        if index >= len(self._table):
            self._resize()
            return self.add(value)
        bucket = self._table[index]
        bucket.set(value)
        self._size += 1

    def remove(self, value: Hashable) -> bool:
        index = self._find_index(value)
        if index >= len(self._table):
            return False
        bucket = self._table[index]
        if not bucket:
            return False
        bucket.clear()
        self._size -= 1
        return True

    def get(self, value: Hashable) -> Any:
        index = self._find_index(value)
        if index >= len(self._table) or not self._table[index]:
            raise KeyError(f"{value} not found")
        return self._table[index].value

    def _add_existing(self, value: Hashable) -> bool:
        index = self._find_index(value)
        if index >= len(self._table):
            return False
        bucket = self._table[index]
        if bucket:
            bucket.set(value)
            return True
        return False

    def _find_index_for_addition(self, value: Hashable) -> int:
        index = self._hash(value)
        step = 1
        result_index = len(self._table)
        while index < len(self._table):
            bucket = self._table[index]
            if bucket.state == self.Bucket.State.OCCUPIED and bucket.value == value:
                return index
            elif bucket.can_set() and result_index == len(self._table):
                result_index = index
            index = self._probing_function(index, step)
            step += 1
        return result_index

    def _find_index(self, value: Hashable, for_add=False) -> int:
        index = self._hash(value)
        step = 1
        while index < len(self._table):
            bucket = self._table[index]
            if for_add and bucket.can_set():
                return index
            elif (bucket.state == self.Bucket.State.EMPTY or
                  bucket.state == self.Bucket.State.OCCUPIED and
                  bucket.value == value
                  ):
                return index
            index = self._probing_function(index, step)
            step += 1
        return index

    def _hash(self, item) -> int:
        return hash(item) % len(self._table)

    def _resize(self):
        new_size = int(len(self._table) * self._resize_factor)
        new_table = [self.Bucket() for _ in range(new_size)]
        for bucket in self._table:
            if bucket:
                index = hash(bucket.value) % new_size
                iteration = 0
                while new_table[index]:
                    index = self._probing_function(index, iteration)
                    iteration += 1
                new_table[index] = bucket
        self._table = new_table
