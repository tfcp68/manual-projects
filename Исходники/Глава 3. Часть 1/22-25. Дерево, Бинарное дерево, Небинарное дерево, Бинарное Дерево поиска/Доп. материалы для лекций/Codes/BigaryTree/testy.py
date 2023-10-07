class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None


class Tree:
    def __init__(self):
        self.root = None

    def __find(self, node, parent, value):
        if node is None:
            return None, parent, False
        if value == node.data:
            return node, parent, True
        if value < node.data:
            if node.left:
                return self.__find(node.left, node, value)
        if value > node.data:
            if node.right:
                return self.__find(node.right, node, value)
        return node, parent, False

    def add(self, obj):
        if self.root is None:
            self.root = obj
            return obj
        node, parent, fl_find = self.__find(self.root, None, obj.data)
        if not fl_find and node:
            if obj.data < node.data:
                node.left = obj
            else:
                node.right = obj
        return obj


    def show_tree(self, node):
        if node is None:
            return
        self.show_tree(node.left)
        print(node.data)
        self.show_tree(node.right)

    def __del_leaf(self, node, parent):
        if parent.left == node:
            parent.left = None
        elif parent.right == node:
            parent.right = None

    def __del_one_child(self, node, parent):
        if parent.left == node:
            if node.left is None:
                parent.left = node.right
            elif node.right is None:
                parent.left = node.left
        elif parent.right == node:
            if node.left is None:
                parent.right = node.right
            elif node.right is None:
                parent.right = node.left

    def __find_min(self, node, parent):
        if node.left:
            return self.__find_min(node.left, node)
        return node, parent

    def del_node(self, key):
        node, parent, fl_find = self.__find(self.root, None, key)

        if not fl_find:
            return None

        if node.left is None and node.right is None:
            self.__del_leaf(node, parent)
        elif node.left is None or node.right is None:
            self.__del_one_child(node, parent)
        else:
            nods, parents = self.__find_min(node.right, node)
            node.data = nods.data
            self.__del_one_child(nods, parents)

    def fin_tree(self, key):
        node, parent, fl_find = self.__find(self.root, None, key)

        if not fl_find:
            return False
        else:
            return True




t = Tree()
t.add(Node(10))
# t.add(Node(152))
# t.add(Node(45))
# t.add(Node(45))
# t.add(Node(45))
# t.add(Node(75))
# t.add(Node(412))


t.del_node(75)
t.del_node(75)

t.show_tree(t.root)
print(t.fin_tree(45))