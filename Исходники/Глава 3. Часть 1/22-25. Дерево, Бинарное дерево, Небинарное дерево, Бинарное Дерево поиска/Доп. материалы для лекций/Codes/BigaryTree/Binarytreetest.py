import random
import pytest
from Binarytree import Node, BinaryTree

def test_add_node_single():
    # Создание дерева
    tree = BinaryTree()

    # Добавление узла
    tree.add_node(5)

    # Проверка корректности добавления узла
    assert tree.root.value == 5

def test_add_node_left():
    # Создание дерева
    tree = BinaryTree()

    # Добавление узлов
    tree.add_node(5)
    tree.add_node(3)

    # Проверка корректности добавления узла
    assert tree.root.value == 5
    assert tree.root.left.value == 3

def test_add_node_right():
    # Создание дерева
    tree = BinaryTree()

    # Добавление узлов
    tree.add_node(5)
    tree.add_node(7)

    # Проверка корректности добавления узла
    assert tree.root.value == 5
    assert tree.root.right.value == 7

def test_random_add():
    adf = []
    tree = BinaryTree()

    for i in range(100):
        f = random.randint(0, 10)
        adf.append(f)
        adf.sort()
        tree.add_node(f)
    tree.tree_traversal()
    assert adf == tree.list

def test_delete_node_random():
    # Создание дерева
    tree = BinaryTree()
    adf = []
    # Добавление 100 случайных узлов
    for i in range(100):
        f = random.randint(0, 10)
        adf.append(f)
        adf.sort()
        tree.add_node(f)
    # удаление случайных узлов
    for i in range(100):
        f = random.randint(0, 10)
        if f in adf:
            adf.remove(f)
            adf.sort()
        tree.delete_node(f)
    tree.tree_traversal()
    assert tree.list == adf

def test_delete_node_random_1():
    # Создание дерева
    tree = BinaryTree()
    #удаление несуществующих узлов
    for i in range(20):
        f = random.randint(0, 10)
        tree.delete_node(f)
    tree.tree_traversal()
    assert len(tree.list)==0

def test_find():
    tree = BinaryTree()
    adf = []
    # Добавление 100 случайных узлов
    for i in range(100):
        f = random.randint(0, 5000)
        adf.append(f)
        adf.sort()
        tree.add_node(f)
    find_s = []
    for i in range(100):
        f = random.randint(0, 5000)
        if (tree.find_node(f) == False and (f in adf != False)) or \
                (tree.find_node(f) != False and (f in adf == False)):
            find_s.append(1)
    assert len(find_s) == 0

def test_delete_node_all():
    # Создание дерева
    tree = BinaryTree()
    adf = []
    # Добавление 100 случайных узлов
    for i in range(100):
        f = random.randint(0, 10)
        adf.append(f)
        adf.sort()
        tree.add_node(f)
    # удаление случайных узлов
    for i in range(100):
        f = random.choice(adf)
        adf.remove(f)
        adf.sort()
        tree.delete_node(f)
    # удаление случайных узлов
    for i in range(100):
        f = random.randint(0, 10)
        if f in adf:
            adf.remove(f)
            adf.sort()
        tree.delete_node(f)
    tree.tree_traversal()
    assert tree.list == adf