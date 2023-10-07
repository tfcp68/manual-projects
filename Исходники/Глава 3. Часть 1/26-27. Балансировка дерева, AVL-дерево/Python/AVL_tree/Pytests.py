import pytest
START_COUNTER = 1
FINAL_COUNTER = 100


from AVL_tree import AVLTree


def PrintTree(TREE):
    l = []
    for data in TREE:
        l.append(data)
    return l


def Make_tree(start_counter, final_counter):
    TREE = AVLTree()
    for i in range(start_counter, final_counter):
        TREE.insert_node(i, i)
    array = []
    for i in range(start_counter, final_counter):
        array.append(i)
    return PrintTree(TREE), array


def Delete_tree(start_counter, final_counter):
    TREE = AVLTree()
    for i in range(start_counter, final_counter):
        TREE.insert_node(i, i)
    for i in range(start_counter, final_counter):
        TREE.delete_node(i)
    return PrintTree(TREE)


def Find_node(start_counter, final_counter):
    TREE = AVLTree()
    for i in range(start_counter, final_counter):
        TREE.insert_node(i, i)
    array = []
    for i in range(start_counter, final_counter):
        array.append(i)
    array2 =[]
    for i in range(start_counter, final_counter):
        a = TREE.find_node(i)
        array2.append(a)
    return array2, array


def find_node(n):
    TREE = AVLTree()
    for i in range(0, n):
        TREE.insert_node(i, i)
    print(TREE.find_node(4))


def delete_more_node():
    TREE = AVLTree()
    for i in range(0, 1):
        TREE.insert_node(i, i)
    TREE.delete_node(1)
    TREE.delete_node(1)
    return PrintTree(TREE)


def delete_node():
    TREE = AVLTree()
    TREE.delete_node(0)
    TREE.delete_node(1)
    return PrintTree(TREE)

def test1():
    """
    тестирование на правильную вставку элементов
    :return:
    """
    one, two = Make_tree(START_COUNTER, FINAL_COUNTER)
    assert one, two


def test2():
    """
    тестирование на полное удаление дерева
    :return:
    """
    assert Delete_tree(START_COUNTER, FINAL_COUNTER) == []

def test3():
    """
    тестирование на поиск всех элементов в дереве
    :return:
    """
    one, two = Find_node(START_COUNTER, FINAL_COUNTER)
    assert one == two

def test_exeption4():
    """
    тестирование на удаления из пустого дерева
    :return:
    """
    with pytest.raises(AttributeError):
        find_node(0)


def test_exeption5():
    """
    тестирование на поиск несуществующего дерева
    :return:
    """
    with pytest.raises(AttributeError):
        find_node(1)


def test6():
    """
    тестирование на удаления элементов которых нету в дереве
    :return:
    """
    assert delete_more_node() == [0]


def test7():
    """тестирования на удаление из пустого дерева"""
    assert delete_node() == []