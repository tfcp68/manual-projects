import numpy as np
from numpy import random


def gen_matrix():
    matrix = np.array(random.randint(2, size=(10, 10)))
    return matrix


def r_adjacency_list(matrix):
    adjacency_list = [[] for count_node in range(len(matrix))]

    for from_node in range(len(matrix)):
        for to in range(len(matrix[from_node])):
            if matrix[from_node][to]:
                matrix[to][from_node] = 1
            matrix[from_node][from_node] = 0

    for from_node in range(len(matrix)):
        for to in range(len(matrix[from_node])):
            if matrix[from_node][to]:
                adjacency_list[from_node].append(to)
    return adjacency_list


def r_data_list(matrix):
    data_list = []

    for from_node in range(len(matrix)):
        for to in range(len(matrix[from_node])):
            data = random.randint(1, 50)
            if matrix[from_node][to]:
                matrix[from_node][to] = data
                matrix[to][from_node] = data

    for from_node in range(len(matrix)):
        for to in range(len(matrix[from_node])):
            if matrix[from_node][to] != 0:
                data_list.append(matrix[from_node][to])
    return data_list



