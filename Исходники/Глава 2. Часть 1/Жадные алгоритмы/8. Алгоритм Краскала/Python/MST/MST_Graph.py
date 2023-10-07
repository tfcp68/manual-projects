from random import randint
from UnionFind import UnionFind


class Edge:
    def __init__(self, from_node, to, data):
        self.from_node = from_node
        self.to = to
        self.data = data


class Tree:
    def __init__(self):
        self.edges_tree = []

    def add_edge(self, edge):
        self.edges_tree.append(edge)

    def get_list_edges(self):
        return self.edges_tree


class Graph:
    def __init__(self, adjacency_list, data_list):
        self._edges_graph = list()
        self._data_list = data_list
        self._adjacency_list = adjacency_list
        self._set_adjacency_list = False
        Graph._set_adjacency_list(self)
        self._kraskal_tree = Tree()
        self._prima_tree = Tree()

    def _set_adjacency_list(self):
        try:
            index_data = 0
            for from_node in range(len(self._adjacency_list)):
                for to in self._adjacency_list[from_node]:
                    data = self._data_list[index_data]
                    self._edges_graph.append(Edge(from_node, to, data))
                    index_data += 1
            if Graph.__check_connect(self._adjacency_list, self._edges_graph):
                self._set_adjacency_list = True
        except IndexError:
            self._set_adjacency_list = False

    @staticmethod
    def __check_connect(adjacency_list, edges):
        node_visit = {edges[0].from_node, edges[0].to}
        for count in range(len(adjacency_list)):
            for edge in edges:
                if edge.from_node in node_visit or edge.to in node_visit:
                    node_visit.add(edge.from_node)
                    node_visit.add(edge.to)
        if len(node_visit) != len(adjacency_list):
            return False
        return True

    def get_list_edges_graph(self):
        return self._edges_graph

    def tree_prima(self):

        # Если список смежности установлен
        if self._set_adjacency_list:
            edges = self._edges_graph
            nodes_visit = set()

            # Выбрать случайную вершину и добавить её в список посещенных
            nodes_visit.add(randint(0, len(self._adjacency_list) - 1))

            # Пока не посетим все вершины
            while len(nodes_visit) != len(self._adjacency_list):

                # Выбрать минимальное ребро
                min_edge = Graph.__return_min_edge(edges, nodes_visit)

                # Добавить минимальное ребро в дерево
                self._prima_tree.add_edge(min_edge)
            return self._prima_tree.edges_tree

    def tree_kraskal(self):

        # Если список смежности установлен
        if self._set_adjacency_list:

            vertex = len(self._adjacency_list)
            group_nodes = UnionFind(vertex)
            edges = sorted(self._edges_graph, key=Graph.__compare)
            for edge in edges:

                # Если вершины из разных групп
                if not group_nodes.same_set(edge.from_node, edge.to):

                    # Добавляем ребро в дерево
                    self._kraskal_tree.add_edge(edge)

                    # Объединяем группы вершин
                    group_nodes.union_set(edge.from_node, edge.to)
            return self._kraskal_tree.edges_tree

    def print_tree_kraskal(self):
        tree = str()
        for edge in self._kraskal_tree.get_list_edges():
            tree += f'{edge.from_node}---{edge.to}  {edge.data}\n'
        print(tree)

    def print_tree_prima(self):
        tree = str()
        for edge in self._prima_tree.get_list_edges():
            tree += f'{edge.from_node}---{edge.to}  {edge.data}\n'
        print(tree)

    @staticmethod
    def __compare(edge):
        return edge.data

    @staticmethod
    def __return_min_edge(edges, nodes_visit):
        array_edges = []
        for edge in edges:

            # Если одна из вершин есть в списке посещённых
            if (edge.from_node in nodes_visit
                    or edge.to in nodes_visit):

                # Если одной из вершин нет в списке посещённых
                if (edge.from_node not in nodes_visit
                        or edge.to not in nodes_visit):

                    # Добавить ребро в список
                    array_edges.append(edge)

        # Выбрать минимальное ребро из списка
        min_edge = min(array_edges, key=Graph.__compare)

        # Очистить список ребер
        array_edges.clear()

        # Добавить вершины минимального ребра в список посещённых
        nodes_visit.add(min_edge.from_node)
        nodes_visit.add(min_edge.to)
        return min_edge





