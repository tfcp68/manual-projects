from typing import TypeVar, Callable, Iterable, overload

T = TypeVar('T')


class SegmentTree(Iterable[T]):
    def __init__(self,
                 n: int,
                 func: Callable[[T, T], T],
                 neutral: T):
        self._n = 2 ** (n - 1).bit_length()
        self._neutral = neutral
        self._func = func
        self._tree = [neutral for _ in range(2 * self._n)]

    def __len__(self) -> int:
        return self._n

    @overload
    def __getitem__(self, index: int) -> T:
        ...

    @overload
    def __getitem__(self, index: slice) -> Iterable[T]:
        ...

    @overload
    def __setitem__(self, index: int, value: T):
        ...

    @overload
    def __setitem__(self, index: slice, value: Iterable[T]):
        ...

    def __iter__(self) -> Iterable[T]:
        return iter(self[0:self._n])

    def clear(self):
        for i in range(len(self._tree)):
            self._tree[i] = self._neutral

    def build(self, data: Iterable[T]):
        self.clear()
        for i, item in zip(range(self._n), data):
            self._tree[i + self._n] = item
        self._rebuild_tree(self._n, 2 * self._n)

    def update(self, index: int, value: T):
        if index >= self._n:
            raise IndexError(f"Index {index} out of range [0, {self._n})")
        index += self._n
        self._tree[index] = value
        self._rebuild_tree(index, index + 1)

    def query(self, l: int, r: int) -> T:
        if l >= r:
            raise ValueError(f"Invalid range [{l}, {r})")
        if not (0 <= l < r <= self._n):
            raise IndexError(f"Range [{l}, {r}) out of range [0, {self._n})")
        l += self._n
        r += self._n - 1
        result = self._neutral
        while l < r:
            if self._is_right_child(l):
                result = self._func(result, self._get_node_value(l))
                l += 1
            if self._is_left_child(r):
                result = self._func(self._get_node_value(r), result)
                r -= 1
            l = self._parent(l)
            r = self._parent(r)
        if l == r:
            result = self._func(result, self._get_node_value(l))
        return result

    def _rebuild_tree(self, l, r):
        while l > 0:
            if self._is_right_child(l):
                self._tree[self._parent(l)] = self._func(
                    self._get_node_value(l - 1), self._get_node_value(l))
                l += 1
            if self._is_left_child(r - 1):
                self._tree[self._parent(r)] = self._func(
                    self._get_node_value(r - 1), self._get_node_value(r)
                )
                r -= 1
            for i in range(l, r, 2):
                self._tree[self._parent(i)] = self._func(
                    self._get_node_value(i), self._get_node_value(i + 1))
            l = self._parent(l)
            r = self._parent(r)

    def _left_child(self, node):
        return 2 * node

    def _right_child(self, node):
        return 2 * node + 1

    def _parent(self, node):
        return node // 2

    def _is_left_child(self, node):
        return not self._is_root(node) and node % 2 == 0

    def _is_right_child(self, node):
        return not self._is_root(node) and node % 2 == 1

    def _is_root(self, node):
        return node < 2

    def _get_node_value(self, node):
        if not (0 <= node < 2 * self._n):
            return self._neutral
        return self._tree[node]

    def __getitem__(self, index):
        if isinstance(index, slice):
            return self.__getitem__slice(index)
        return self.__getitem__single(index)

    def __getitem__slice(self, index: slice) -> Iterable[T]:
        start = index.start or 0
        stop = index.stop or self._n
        step = index.step or 1
        if not (0 <= start < stop <= self._n):
            raise IndexError(
                f"Range [{start}, {stop}) out of range [0, {self._n})")
        return (self._tree[i + self._n] for i in range(start, stop, step))

    def __getitem__single(self, index: int) -> T:
        if index >= self._n:
            raise IndexError(f"Index {index} out of range [0, {self._n})")
        return self._tree[index + self._n]

    def __setitem__(self, index, value):
        if isinstance(index, slice) and isinstance(value, Iterable):
            return self.__setitem__slice(index, value)
        if isinstance(index, int):
            return self.__setitem__single(index, value)
        raise TypeError("Invalid argument types")

    def __setitem__slice(self, index: slice, value: Iterable[T]):
        start = index.start or 0
        stop = index.stop or self._n
        step = index.step or 1
        if not (0 <= start < stop <= self._n):
            raise IndexError(
                f"Range [{start}, {stop}) out of range [0, {self._n})")
        for i, item in zip(range(start, stop, step), value):
            self._tree[i + self._n] = item
        self._rebuild_tree(start + self._n, stop + self._n)

    def __setitem__single(self, index: int, value: T):
        self.update(index, value)
