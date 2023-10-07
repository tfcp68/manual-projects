from Node import Node
from Iterator import Iterator


class AVLTree:

    def __init__(self, __key=None):
        """

        :param __key: компаратор
        :variable root: корень дерева
        """
        self.__root = None
        self.__key = __key if __key is not None else lambda x:x

    def __iter__(self):
        return Iterator(self.__root)

    def find_node(self, key):
        """
        поиск вершины, функция для пользователя
        :param key: ключ который необходимо найти
        :return: данные ключа
        """
        return self.__find_node_recursive(self.__root, key)

    def __find_node_recursive(self, root, key):
        """
        рекурсивная функция поиска вершины
        :param root: корень поддерева
        :param key: ключ которым необходимо найти
        :return: данные найденой вершины
        """
        if root:
            if key == root.key:
                return root.data
            if key < root.key:
                return self.__find_node_recursive(root.left, key)
            else:
                return self.__find_node_recursive(root.right, key)
        else:
            raise AttributeError("no such value")

    def find_min(self, root):
        """
        функция поиска минимального элемента
        :param root: корень поддерева
        :return: найденный элемент
        """
        if root.left:
            return self.find_min(root.left)
        else:
            return root

    def delete_min(self, root):
        """
        удаление минимального элемента из дерева
        :param root: корень текущего поддеерева
        :return: корень поддерева, с удалённым элементом
        """
        if root.left:
            root.left = self.delete_min(root.left)
        if not root.left:
            return root.right
        return root.make_balance(root)

    def insert_node(self, key, data):
        """
        функция всавки для поьзователя
        :param key: ключ нового элемента
        :param data: данные нового элемента
        :return: корень дерева с вставленным элементом
        """
        self.__root = self.__insert_node_recursive(self.__root, key, data)

    def __insert_node_recursive(self, root, key, data):
        """
        вставка элемента
        :param root: корень поддерева
        :param key: ключ нового элемента
        :param data: данные нового элемента
        :return: корень дерева с вставленным элементом
        """
        if not root:
            return Node(key, data)
        if key < root.key:
            root.left = self.__insert_node_recursive(root.left, key, data)
        if key >= root.key:
            root.right = self.__insert_node_recursive(root.right, key, data)
        return root.make_balance(root)

    def delete_node(self, key):
        """
        функция удаления для пользователя
        :param key: ключ уаляемой вершины
        :return: корень дерева с удалённой вершиной
        """
        self.__root = self.__delete_node_recursive(self.__root, key)

    def __delete_node_recursive(self, root, key):
        """
        функция удаления
        :param root: корень поддерева
        :param key: ключ удаляемой вершины
        :return: корень дерева с удалённой вершиной
        """
        if not root:
            return 0
        if key < root.key:
            root.left = self.__delete_node_recursive(root.left, key)
        if key >= root.key:
            root.right = self.__delete_node_recursive(root.right, key)
        if key == root.key:
            left = root.left
            right = root.right
            if not right:
                return left
            min = self.find_min(right)
            min.right = self.delete_min(right)
            min.left = left
            return min.make_balance(min)
        return root.make_balance(root)

