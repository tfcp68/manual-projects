class Iterator:
    """
    итератор по дереву
    """
    def __init__(self, _node):
        """

        :param _node: корень дерева
        :variable stack: стек для хранения уже пройденых вершин
        """
        self.stack = []
        self.node = _node

    def __iter__(self):
        return self

    def __next__(self):
        """
        итератор по всем вершинам дерева, от большей к меньшей
        :return: данные который хранит вершина
        """
        while self.node or len(self.stack) > 0:
            if self.node:
                self.stack.append(self.node)
                self.node = self.node.left
            else:
                self.node = self.stack.pop()
                result = self.node.data
                self.node = self.node.right
                return result
        raise StopIteration

