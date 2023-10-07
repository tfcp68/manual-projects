import random
from list import list_tree
import pytest
def test_add_node_single():
    # Создание дерева
    tree = list_tree()

    # Добавление узла
    tree.insert(5)

    # Проверка корректности добавления узла
    assert tree.tree[0] == 5

def test_add_node_left():
    # Создание дерева
    tree = list_tree()

    # Добавление узлов
    tree.insert(5)
    tree.insert(3)

    # Проверка корректности добавления узла
    assert tree.tree[0] == 5
    assert tree.tree[1] == 3

def test_add_node_left():
    # Создание дерева
    tree = list_tree()

    # Добавление узлов
    tree.insert(5)
    tree.insert(6)

    # Проверка корректности добавления узла
    assert tree.tree[0] == 5
    assert tree.tree[2] == 6
#
def test_random_add():
    adf = []
    tree = list_tree()

    for i in range(100):
        f = random.randint(1, 100)
        adf.append(f)
        adf.sort()
        tree.insert(f)
    k = 0
    for i in tree.tree:
        if i != 0:
            k += 1
    assert len(adf) == k

def tese_find():
    # Создание дерева
    tree = list_tree()
    adf = []
    # Добавление 100 случайных узлов
    for i in range(100):
        f = random.randint(1, 1000)
        adf.append(f)
        adf.sort()
        tree.insert(f)
    f = random.randint(1, 1000)
    l = tree.find(f)
    assert (f in adf) and (l!=-1) or (not (f in adf)) and (l ==-1)

def test_delete_node_random():
    # Создание дерева
    tree = list_tree()
    adf = []
    # Добавление 100 случайных узлов
    for i in range(100):
        f = random.randint(1, 20)
        adf.append(f)
        adf.sort()
        tree.insert(f)
    # удаление случайных узлов
    for i in range(100):
        f = random.randint(1, 20)
        if f in adf:
            adf.remove(f)
            adf.sort()
        tree.erase(f)
    k = 0
    for i in tree.tree:
        if i != 0:
            k += 1
    assert len(adf) == k


def test_delete_node_all():
    # Создание дерева
    tree = list_tree()
    adf = []
    # Добавление 100 случайных узлов
    for i in range(100):
        f = random.randint(1, 10)
        adf.append(f)
        adf.sort()
        tree.insert(f)
    # удаление случайных узлов из списка
    for i in range(100):
        f = random.choice(adf)
        adf.remove(f)
        adf.sort()
        tree.erase(f)
    # удаление случайных узлов
    for i in range(100):
        f = random.randint(1, 10)
        if f in adf:
            adf.remove(f)
            adf.sort()
        tree.erase(f)
    k = 0
    for i in tree.tree:
        if i != 0:
            k += 1
    assert len(adf) == k


