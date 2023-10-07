from Iterator import Iterator

class Node:
    """
    класс элемента дерева
    """

    def __init__(self, _key, _data):
        """
        конструктор класса
        :param _key: ключ по которому идёт сравнение
        :param _data: данные пользователя
        :variable height высота элемента
        :variable left левое поддерева
        :variable right правое поддерево
        """
        self.key = _key
        self.data = _data
        self.height: int = 1
        self.left = None
        self.right = None

    def __iter__(self):
        return Iterator(self)

    def get_height(self, node):
        """

        :param node: элемент дерева
        :return: высоту элемента дерева
        """
        if node:
            return node.height
        else:
            return 0

    def get_balance_factor(self, node):
        """

        :param node: элемент дерева
        :return: коэффицент баланса дерева
        """
        if node:
            return node.get_height(node.left) - node.get_height(node.right)
        else:
            return 0

    def fix_height(self, node):
        """
        исправляет высоту вершины
        :param node: элемент дерева
        """
        node.height = max(node.left.height if node.left else 0, node.right.height if node.right else 0) + 1
        pass

    def right_rotate(self, node):
        """
        правый поворот
        :param node: корень поддерева нуждающегося в балансировке
        :return: новый корень поддерева
        """
        q: Node = node.right
        node.right = q.left
        q.left = node
        q.fix_height(q)
        node.fix_height(node)
        return q

    def left_rotate(self, node):
        """
        левый поворот
        :param node: корень поддерева нуждающегося в балансировке
        :return: новый корень поддерева
        """
        q: Node = node.left
        node.left = q.right
        q.right = node
        q.fix_height(q)
        node.fix_height(node)
        return q

    def make_balance(self, node):
        """
        проверяет необходимость балансировки
        :param node: корень поддерева нуждающегося в балансировке
        :return: новый корень
        """
        node.fix_height(node)
        if self.get_balance_factor(node) > 1:
            if self.get_balance_factor(node.left) < 0:
                node.left = node.right_rotate(node.left)
            return node.left_rotate(node)

        if self.get_balance_factor(node) < -1:
            if self.get_balance_factor(node.right) > 0:
                node.right = node.left_rotate(node.right)
            return node.right_rotate(node)

        return node
