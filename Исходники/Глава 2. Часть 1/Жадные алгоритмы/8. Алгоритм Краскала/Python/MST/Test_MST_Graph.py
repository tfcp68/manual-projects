from CheckConnect import check_connect
from SetAdjacencyList import set_adjacency_list
from UnionFind import UnionFind
from MST_Graph import Graph
import unittest
import MinEdge
import RandomGraph
import TreeOrNot


class TestSetAdjacencyList(unittest.TestCase):
    def test_1(self):
        list_adjacency = []
        list_data = [1, 2, 3]
        res = set_adjacency_list(list_adjacency, list_data)
        self.assertEqual(res, 'Некорректные данные.')

    def test_2(self):
        list_adjacency = []
        list_data = [[1, 2],
                     [0, 3],
                     [0, 5, 4],
                     [1, 4, 5],
                     [2, 3],
                     [2, 3]]
        res = set_adjacency_list(list_adjacency, list_data)
        self.assertEqual(res, 'Некорректные данные.')

    def test_3(self):
        list_adjacency = []
        list_data = []
        res = set_adjacency_list(list_adjacency, list_data)
        self.assertEqual(res, 'Некорректные данные.')

    def test_4(self):
        list_adjacency = [[1, 2]]
        list_data = []
        res = set_adjacency_list(list_adjacency, list_data)
        self.assertEqual(res, 'Некорректные данные.')

    def test_5(self):
        list_adjacency = []
        list_data = [1]
        res = set_adjacency_list(list_adjacency, list_data)
        self.assertEqual(res, 'Некорректные данные.')

    def test_6(self):
        list_adjacency = [[1]]
        list_data = [1]
        res = set_adjacency_list(list_adjacency, list_data)
        self.assertEqual(len(list_adjacency), res)

    def test_7(self):
        list_adjacency = [[1], [2]]
        list_data = [1, 2]
        res = set_adjacency_list(list_adjacency, list_data)
        self.assertEqual(len(list_adjacency), res)

    def test_8(self):
        list_adjacency = [[1, 2], [3, 4], [2, 0]]
        list_data = [1, 3, 4, 1, 2, 3]
        res = set_adjacency_list(list_adjacency, list_data)
        self.assertEqual(len(list_adjacency), res)

    def test_9(self):
        list_adjacency = [[1, 2], [3, 4], [2, 0]]
        list_data = [1, 3, 4, 1, 2, 5]
        res = set_adjacency_list(list_adjacency, list_data)
        self.assertEqual(len(list_adjacency), res)

    def test_10(self):
        list_adjacency = [[1, 2], [3, 4], [2, 0], [1, 2, 4], [1], [1, 2, 3]]
        list_data = [1, 3, 4, 1, 2, 5, 1, 2, 4, 5, 7, 8, 9]
        res = set_adjacency_list(list_adjacency, list_data)
        self.assertEqual(len(list_adjacency), res)


class TestCheckConnect(unittest.TestCase):
    def test_1(self):
        adjacency_list =[[1, 2],
                        [0, 3],
                        [0, 3, 5],
                        [1, 2, 4],
                        [3, 5],
                        [2, 4]]
        list_data = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14]
        graph = Graph(adjacency_list, list_data)
        edges = graph.get_list_edges_graph()
        res = check_connect(adjacency_list, edges)
        self.assertEqual(res, True)

    def test_2(self):
        adjacency_list =[[1, 2],
                        [0, 3, 5],
                        [0, 3, 4, 6],
                        [1, 2, 6],
                        [2],
                        [1],
                        [2, 3]]
        list_data = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16]
        graph = Graph(adjacency_list, list_data)
        edges = graph.get_list_edges_graph()
        res = check_connect(adjacency_list, edges)
        self.assertEqual(res, True)

    def test_3(self):
        adjacency_list =[[1, 2],
                        [0, 3],
                        [0, 3],
                        [1, 2],
                        [5],
                        [4]]
        list_data = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
        graph = Graph(adjacency_list, list_data)
        edges = graph.get_list_edges_graph()
        res = check_connect(adjacency_list, edges)
        self.assertEqual(res, False)

    def test_4(self):
        adjacency_list =[[1, 2],
                        [0, 3],
                        [0, 3],
                        [1, 2],
                        []]
        list_data = [1, 2, 3, 4, 5, 6, 7, 8]
        graph = Graph(adjacency_list, list_data)
        edges = graph.get_list_edges_graph()
        res = check_connect(adjacency_list, edges)
        self.assertEqual(res, False)

    def test_5(self):
        adjacency_list =[[1, 2],
                        [0, 3],
                        [0, 3],
                        [1, 2],
                        [5, 6],
                        [4, 7],
                        [4, 7],
                        [5, 6]]
        list_data = [1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8]
        graph = Graph(adjacency_list, list_data)
        edges = graph.get_list_edges_graph()
        res = check_connect(adjacency_list, edges)
        self.assertEqual(res, False)


class TestReturnMinEdge(unittest.TestCase):
    def test_1(self):
        list_adjacency = [[1, 2],
                          [0, 3],
                          [0, 5, 4],
                          [1, 4, 5],
                          [2, 3],
                          [2, 3]]
        list_data = [1, 5, 1, 3, 5, 7, 1, 3, 6, 11, 1, 6, 7, 11]
        graph = Graph(list_adjacency, list_data)
        node_visit = {0}
        edges = graph.get_list_edges_graph()
        res = MinEdge.return_min_edge(edges, node_visit)
        self.assertEqual(res.data, 1)

    def test_2(self):
        list_adjacency = [[1, 2],
                          [0, 3],
                          [0, 4, 5],
                          [1, 4, 5],
                          [2, 3],
                          [2, 3]]
        list_data = [1, 5, 1, 3, 5, 1, 1, 3, 7, 6, 1, 7, 1, 6]

        graph = Graph(list_adjacency, list_data)
        node_visit = {0, 1}
        edges = graph.get_list_edges_graph()
        res = MinEdge.return_min_edge(edges, node_visit)
        self.assertEqual(res.data, 3)

    def test_3(self):
        list_adjacency = [[1, 2],
                          [0, 3],
                          [0, 4, 5],
                          [1, 4, 5],
                          [2, 3],
                          [2, 3]]
        list_data = [1, 5, 1, 3, 5, 1, 1, 3, 7, 6, 1, 7, 1, 6]

        graph = Graph(list_adjacency, list_data)
        node_visit = {5}
        edges = graph.get_list_edges_graph()
        res = MinEdge.return_min_edge(edges, node_visit)
        self.assertEqual(res.data, 1)

    def test_4(self):
        list_adjacency = [[1, 2],
                          [0, 3],
                          [0, 4, 5],
                          [1, 4, 5],
                          [2, 3],
                          [2, 3]]
        list_data = [1, 5, 1, 3, 5, 1, 1, 3, 7, 6, 1, 7, 1, 6]

        graph = Graph(list_adjacency, list_data)
        node_visit = {2}
        edges = graph.get_list_edges_graph()
        res = MinEdge.return_min_edge(edges, node_visit)
        self.assertEqual(res.data, 1)

    def test_5(self):
        list_adjacency = [[1, 2],
                          [0, 3],
                          [0, 4, 5],
                          [1, 4, 5],
                          [2, 3],
                          [2, 3],
                          [3]]
        list_data = [1, 5, 1, 3, 5, 1, 1, 3, 7, 6, 1, 7, 1, 6, 2]

        graph = Graph(list_adjacency, list_data)
        node_visit = {3}
        edges = graph.get_list_edges_graph()
        res = MinEdge.return_min_edge(edges, node_visit)
        self.assertEqual(res.data, 2)

    def test_6(self):
        list_adjacency = [[1, 2],
                          [0, 3],
                          [0, 4, 5],
                          [1, 4, 5],
                          [2, 3],
                          [2, 3]]
        list_data = [1, 5, 1, 3, 5, 1, 1, 3, 7, 6, 1, 7, 1, 6]

        graph = Graph(list_adjacency, list_data)
        node_visit = {4}
        edges = graph.get_list_edges_graph()
        res = MinEdge.return_min_edge(edges, node_visit)
        self.assertEqual(res.data, 1)


class TestTreePrima(unittest.TestCase):
    def test_1(self):
        list_adjacency = [[1, 2],
                          [0, 3],
                          [0, 4, 5],
                          [1, 4, 5],
                          [2, 3],
                          [2, 3]]
        list_data = [1, 5, 1, 3, 5, 1, 1, 3, 7, 6, 1, 7, 1, 6]
        graph = Graph(list_adjacency, list_data)
        res = []
        edges = graph.tree_prima()
        for edge in edges:
            res.append(edge.data)
        self.assertEqual(sorted(res), [1, 1, 1, 3, 5])

    def test_2(self):
        list_adjacency = [[1, 2, 6, 7],
                          [0, 3, 6],
                          [0, 4, 5, 7],
                          [1, 4, 5],
                          [2, 3],
                          [2, 3],
                          [0, 1, 7],
                          [0, 2, 6]]
        list_data = [1, 5, 1, 4, 1, 3, 7, 5, 1, 1, 2, 3, 7, 6, 1, 7, 1, 6, 1, 7, 3, 4, 2, 3]
        graph = Graph(list_adjacency, list_data)
        res = []
        edges = graph.tree_prima()
        for edge in edges:
            res.append(edge.data)
        self.assertEqual(sorted(res), [1, 1, 1, 1, 2, 3, 3])

    def test_3(self):
        list_adjacency = [[2, 7],
                          [3, 6],
                          [0, 4, 5, 7],
                          [1, 4, 5],
                          [2, 3],
                          [2, 3],
                          [1, 7],
                          [0, 2, 6]]
        list_data = [5, 4, 3, 7, 5, 1, 1, 2, 3, 7, 6, 1, 7, 1, 6, 7, 3, 4, 2, 3]
        graph = Graph(list_adjacency, list_data)
        res = []
        edges = graph.tree_prima()
        for edge in edges:
            res.append(edge.data)
        self.assertEqual(sorted(res), [1, 1, 2, 3, 3, 4, 6])

    def test_4(self):
        list_adjacency = [[2],
                          [3, 6],
                          [0, 4, 5, 7],
                          [1, 4, 5],
                          [2, 3],
                          [2, 3],
                          [1, 7],
                          [2, 6]]
        list_data = [5, 3, 7, 5, 1, 1, 2, 3, 7, 6, 1, 7, 1, 6, 7, 3, 2, 3]
        graph = Graph(list_adjacency, list_data)
        res = []
        edges = graph.tree_prima()
        for edge in edges:
            res.append(edge.data)
        self.assertEqual(sorted(res), [1, 1, 2, 3, 3, 5, 6])

    def test_5(self):
        list_adjacency = [[2, 5],
                          [3, 5],
                          [0, 4, 5],
                          [1, 4, 5],
                          [2, 3],
                          [0, 1, 2, 3]]
        list_data = [5, 2, 3, 7, 5, 1, 1, 3, 7, 6, 1, 7, 2, 7, 1, 6]
        graph = Graph(list_adjacency, list_data)
        res = []
        edges = graph.tree_prima()
        for edge in edges:
            res.append(edge.data)
        self.assertEqual(sorted(res), [1, 1, 2, 3, 6])

    def test_6(self):
        list_adjacency = [[2, 5],
                          [3, 5],
                          [0, 5],
                          [1, 4, 5],
                          [3],
                          [0, 1, 2, 3]]
        list_data = [5, 2, 3, 7, 5, 1, 3, 7, 6, 7, 2, 7, 1, 6]
        graph = Graph(list_adjacency, list_data)
        res = []
        edges = graph.tree_prima()
        for edge in edges:
            res.append(edge.data)
        self.assertEqual(sorted(res), [1, 2, 3, 6, 7])

    def test_7(self):
        list_adjacency = [[2, 5],
                          [3, 5],
                          [0, 4],
                          [1, 4, 5],
                          [3, 2],
                          [0, 1, 3]]
        list_data = [5, 2, 3, 7, 5, 1, 3, 7, 6, 7, 1, 2, 7, 6]
        graph = Graph(list_adjacency, list_data)
        res = []
        edges = graph.tree_prima()
        for edge in edges:
            res.append(edge.data)
        self.assertEqual(sorted(res), [1, 2, 3, 5, 6])

    def test_8(self):
        list_adjacency = [[2, 5],
                          [3, 5],
                          [0, 4, 6],
                          [1, 4, 5],
                          [3, 2],
                          [0, 1, 3],
                          [3]]
        list_data = [5, 2, 3, 7, 5, 1, 11, 3, 7, 6, 7, 1, 2, 7, 6, 11]
        graph = Graph(list_adjacency, list_data)
        res = []
        edges = graph.tree_prima()
        for edge in edges:
            res.append(edge.data)
        self.assertEqual(sorted(res), [1, 2, 3, 5, 6, 11])

    def test_9(self):
        list_adjacency = [[2, 5],
                          [3, 5, 7],
                          [0, 4],
                          [1, 4, 5, 6, 7],
                          [2, 3],
                          [0, 1, 3],
                          [3, 7],
                          [1, 3, 6]]
        list_data = [5, 2, 3, 7, 4, 5, 1, 3, 7, 6, 11, 4, 1, 7, 2, 7, 6, 11, 4, 4, 4, 4]
        graph = Graph(list_adjacency, list_data)
        res = []
        edges = graph.tree_prima()
        for edge in edges:
            res.append(edge.data)
        self.assertEqual(sorted(res), [1, 2, 3, 4, 4, 5, 6])

    def test_10(self):
        list_adjacency = [[1, 2, 3],
                          [0, 3],
                          [0, 3],
                          [0, 1, 2]]
        list_data = [4, 5, 1, 4, 1, 5, 11, 1, 1, 11]
        graph = Graph(list_adjacency, list_data)
        res = []
        edges = graph.tree_prima()
        for edge in edges:
            res.append(edge.data)
        self.assertEqual(sorted(res), [1, 1, 5])


class TestUnionFind(unittest.TestCase):
    def test_1(self):
        UF = UnionFind(6)
        UF.union_set(1, 2)
        self.assertEqual(UF.same_set(1, 2), True)

    def test_2(self):
        UF = UnionFind(6)
        UF.union_set(3, 4)
        self.assertEqual(UF.same_set(3, 4), True)

    def test_3(self):
        UF = UnionFind(6)
        UF.union_set(4, 5)
        self.assertEqual(UF.same_set(5, 4), True)

    def test_4(self):
        UF = UnionFind(6)
        self.assertEqual(UF.same_set(3, 2), False)

    def test_5(self):
        UF = UnionFind(6)
        self.assertEqual(UF.same_set(1, 5), False)


class TestTreeKraskal(unittest.TestCase):
    def test_1(self):
        list_adjacency = [[1, 2],
                          [0, 3],
                          [0, 4, 5],
                          [1, 4, 5],
                          [2, 3],
                          [2, 3]]
        list_data = [1, 5, 1, 3, 5, 1, 1, 3, 7, 6, 1, 7, 1, 6]
        graph = Graph(list_adjacency, list_data)
        res = []
        edges = graph.tree_kraskal()
        for edge in edges:
            res.append(edge.data)
        self.assertEqual(sorted(res), [1, 1, 1, 3, 5])

    def test_2(self):
        list_adjacency = [[1, 2, 6, 7],
                          [0, 3, 6],
                          [0, 4, 5, 7],
                          [1, 4, 5],
                          [2, 3],
                          [2, 3],
                          [0, 1, 7],
                          [0, 2, 6]]
        list_data = [1, 5, 1, 4, 1, 3, 7, 5, 1, 1, 2, 3, 7, 6, 1, 7, 1, 6, 1, 7, 3, 4, 2, 3]
        graph = Graph(list_adjacency, list_data)
        res = []
        edges = graph.tree_kraskal()
        for edge in edges:
            res.append(edge.data)
        self.assertEqual(sorted(res), [1, 1, 1, 1, 2, 3, 3])

    def test_3(self):
        list_adjacency = [[2, 7],
                          [3, 6],
                          [0, 4, 5, 7],
                          [1, 4, 5],
                          [2, 3],
                          [2, 3],
                          [1, 7],
                          [0, 2, 6]]
        list_data = [5, 4, 3, 7, 5, 1, 1, 2, 3, 7, 6, 1, 7, 1, 6, 7, 3, 4, 2, 3]
        graph = Graph(list_adjacency, list_data)
        res = []
        edges = graph.tree_kraskal()
        for edge in edges:
            res.append(edge.data)
        self.assertEqual(sorted(res), [1, 1, 2, 3, 3, 4, 6])

    def test_4(self):
        list_adjacency = [[2],
                          [3, 6],
                          [0, 4, 5, 7],
                          [1, 4, 5],
                          [2, 3],
                          [2, 3],
                          [1, 7],
                          [2, 6]]
        list_data = [5, 3, 7, 5, 1, 1, 2, 3, 7, 6, 1, 7, 1, 6, 7, 3, 2, 3]
        graph = Graph(list_adjacency, list_data)
        res = []
        edges = graph.tree_kraskal()
        for edge in edges:
            res.append(edge.data)
        self.assertEqual(sorted(res), [1, 1, 2, 3, 3, 5, 6])

    def test_5(self):
        list_adjacency = [[2, 5],
                          [3, 5],
                          [0, 4, 5],
                          [1, 4, 5],
                          [2, 3],
                          [0, 1, 2, 3]]
        list_data = [5, 2, 3, 7, 5, 1, 1, 3, 7, 6, 1, 7, 2, 7, 1, 6]
        graph = Graph(list_adjacency, list_data)
        res = []
        edges = graph.tree_kraskal()
        for edge in edges:
            res.append(edge.data)
        self.assertEqual(sorted(res), [1, 1, 2, 3, 6])

    def test_6(self):
        list_adjacency = [[2, 5],
                          [3, 5],
                          [0, 5],
                          [1, 4, 5],
                          [3],
                          [0, 1, 2, 3]]
        list_data = [5, 2, 3, 7, 5, 1, 3, 7, 6, 7, 2, 7, 1, 6]
        graph = Graph(list_adjacency, list_data)
        res = []
        edges = graph.tree_kraskal()
        for edge in edges:
            res.append(edge.data)
        self.assertEqual(sorted(res), [1, 2, 3, 6, 7])

    def test_7(self):
        list_adjacency = [[2, 5],
                          [3, 5],
                          [0, 4],
                          [1, 4, 5],
                          [3, 2],
                          [0, 1, 3]]
        list_data = [5, 2, 3, 7, 5, 1, 3, 7, 6, 7, 1, 2, 7, 6]
        graph = Graph(list_adjacency, list_data)
        res = []
        edges = graph.tree_kraskal()
        for edge in edges:
            res.append(edge.data)
        self.assertEqual(sorted(res), [1, 2, 3, 5, 6])

    def test_8(self):
        list_adjacency = [[2, 5],
                          [3, 5],
                          [0, 4, 6],
                          [1, 4, 5],
                          [3, 2],
                          [0, 1, 3],
                          [3]]
        list_data = [5, 2, 3, 7, 5, 1, 11, 3, 7, 6, 7, 1, 2, 7, 6, 11]
        graph = Graph(list_adjacency, list_data)
        res = []
        edges = graph.tree_kraskal()
        for edge in edges:
            res.append(edge.data)
        self.assertEqual(sorted(res), [1, 2, 3, 5, 6, 11])

    def test_9(self):
        list_adjacency = [[2, 5],
                          [3, 5, 7],
                          [0, 4],
                          [1, 4, 5, 6, 7],
                          [2, 3],
                          [0, 1, 3],
                          [3, 7],
                          [1, 3, 6]]
        list_data = [5, 2, 3, 7, 4, 5, 1, 3, 7, 6, 11, 4, 1, 7, 2, 7, 6, 11, 4, 4, 4, 4]
        graph = Graph(list_adjacency, list_data)
        res = []
        edges = graph.tree_kraskal()
        for edge in edges:
            res.append(edge.data)
        self.assertEqual(sorted(res), [1, 2, 3, 4, 4, 5, 6,])

    def test_10(self):
        list_adjacency = [[1, 2, 3],
                          [0, 3],
                          [0, 3],
                          [0, 1, 2]]
        list_data = [4, 5, 1, 4, 1, 5, 11, 1, 1, 11]
        graph = Graph(list_adjacency, list_data)
        res = []
        edges = graph.tree_kraskal()
        for edge in edges:
            res.append(edge.data)
        self.assertEqual(sorted(res), [1, 1, 5])


class TestRandomTest(unittest.TestCase):
    def test_tree_kraskal(self):
        matrix = RandomGraph.gen_matrix()
        adjacency_list = RandomGraph.r_adjacency_list(matrix)
        data_list = RandomGraph.r_data_list(matrix)

        graph = Graph(adjacency_list, data_list)
        tree = graph.tree_kraskal()

        cont_right = 0
        node_visit = set()
        if tree != 0:
            list_adjacency_tree = TreeOrNot.make_list_adjacency_tree(tree)
            for edge in tree:
                node_visit.add(edge.from_node)
                node_visit.add(edge.to)
            if len(node_visit) == len(adjacency_list):
                cont_right += 1
            if TreeOrNot.this_tree_or_not(0, list_adjacency_tree):
                cont_right += 1
            self.assertEqual(cont_right, 2)

    def test_tree_prima(self):
        matrix = RandomGraph.gen_matrix()
        adjacency_list = RandomGraph.r_adjacency_list(matrix)
        data_list = RandomGraph.r_data_list(matrix)

        graph = Graph(adjacency_list, data_list)
        tree = graph.tree_prima()

        cont_right = 0
        node_visit = set()
        if tree != 0:
            list_adjacency_tree = TreeOrNot.make_list_adjacency_tree(tree)
            for edge in tree:
                node_visit.add(edge.from_node)
                node_visit.add(edge.to)
            if len(node_visit) == len(adjacency_list):
                cont_right += 1
            if TreeOrNot.this_tree_or_not(0, list_adjacency_tree):
                cont_right += 1
            self.assertEqual(cont_right, 2)


if __name__ == '__main__':
    unittest.main()
