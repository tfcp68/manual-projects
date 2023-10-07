import random


class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

class BinaryTree:
    def __init__(self):
        self.root = None
        self.list = []
    def add_node(self, value):
        if self.root is None:
            self.root = Node(value)
        else:
            self.__add_node(value, self.root)

    def __add_node(self, value, node):
        if value < node.value:
            if node.left is None:
                node.left = Node(value)
            else:
                self.__add_node(value, node.left)
        else:
            if node.right is None:
                node.right = Node(value)
            else:
                self.__add_node(value, node.right)

    def delete_node(self, value):
        if self.root is not None:
            self.root = self.__delete_node(value, self.root)

    def __delete_node(self, value, node):
        if node is None:
            return node

        if value == node.value:
            if node.left is None:
                return node.right
            elif node.right is None:
                return node.left
            else:
                temp_node = node.right

                while temp_node.left is not None:
                    temp_node = temp_node.left

                node.value = temp_node.value
                node.right = self.__delete_node(node.value, node.right)

        elif value < node.value:
            node.left = self.__delete_node(value, node.left)

        else:
            node.right = self.__delete_node(value, node.right)

        return node

    def tree_traversal(self):
        self.list = []
        if self.root is not None:
            self.__tree_traversal(self.root)

    def __tree_traversal(self, node):
        if node is not None:
            self.__tree_traversal(node.left)
            self.list.append(node.value)
            self.__tree_traversal(node.right)

    def __find_node(self, value, node):
        if node is not None:
            if value == node.value:
                return node
            elif value < node.value:
                return self.__find_node(value, node.left)
            else:
                return self.__find_node(value, node.right)
        else:
            return False

    def find_node(self, value):
        if self.root is not None:
            return self.__find_node(value, self.root)
        else:
            return False
