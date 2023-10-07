from queue import PriorityQueue
from collections import deque


class Edge:
    def __init__(self, fr0m, to):
        self.fr0m = fr0m
        self.to = to


class HaffmanTree:
    def __init__(self, letters: dict[str: int]):
        self._letters = letters
        self._tree = self._build_tree_haffman()
        if self._tree != -1:
            self._root = self._get_root(self._tree)
        else:
            self._root = -1

    @staticmethod
    def _get_root(tree):
        nodes = sorted(tree, key=lambda x: len(x), reverse=True)
        return nodes[0]

    @staticmethod
    def _tree_adjacency_list(tree_edges):
        adjacency_list = dict()
        for edge in tree_edges:
            adjacency_list[edge.fr0m] = list()
            adjacency_list[edge.to] = list()
        for edge in tree_edges:
            adjacency_list[edge.fr0m].append(edge.to)
        return adjacency_list

    def _build_tree_haffman(self):
        if len(letters) > 1:
            edges_tree = list()
            free_nodes = PriorityQueue()
            for data, frequency in self._letters.items():
                free_nodes.put((frequency, data))
            while free_nodes.qsize() > 1:
                left = free_nodes.get()
                right = free_nodes.get()
                parent = (left[0] + right[0], left[1] + right[1])
                free_nodes.put(parent)
                edges_tree.append(Edge(parent[1], left[1]))
                edges_tree.append(Edge(parent[1], right[1]))
            return self._tree_adjacency_list(edges_tree)
        return -1

    @staticmethod
    def _encoding(node, letter, tree):
        if len(node) > 1:
            if letter in tree[node][0]:
                return '0'
            elif letter in tree[node][1]:
                return '1'
        return str()

    def encode_processing(self, word):
        code, visited = str(), list()
        queue = deque()
        if self._root == -1:
            return
        for letter in word:
            queue.append(self._root)
            while queue:
                node = queue.popleft()
                if node not in visited:
                    code += self._encoding(node, letter, self._tree)
                    if node == letter:
                        queue.clear(), visited.clear()
                    else:
                        queue += self._tree[node]
                        visited.append(node)
        return code

    def decode_processing(self, row):
        count, result = 0, str()
        letter = self._root
        if letter == -1:
            return
        while count < len(row):
            digit = row[count]
            if digit == '0':
                letter = self._tree[letter][0]
            else:
                letter = self._tree[letter][1]
            if len(letter) == 1:
                result += letter
                letter = self._root
            count += 1
        return result

    def get_all_codes(self):
        codes = dict()
        if len(letters) > 1:
            for letter in self._letters:
                codes[letter] = self.encode_processing(letter)
            return codes


letters = {'a': 15, 'b': 7, "f": 23}
tree_haffman = HaffmanTree(letters)
print(tree_haffman.get_all_codes())
print(tree_haffman.encode_processing('abf'))
#print(tree_haffman.decode_processing('1101100101000010'))


