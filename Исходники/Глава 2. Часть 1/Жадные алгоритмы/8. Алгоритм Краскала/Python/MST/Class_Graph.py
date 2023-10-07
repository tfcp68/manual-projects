from random import randint


class Edge:
    def __init__(self, from_node, to, data):
        self.from_node = from_node
        self.to = to
        self.data = data


class Tree:
    def __init__(self):
        self.list_edges_tree = []

    def append_edge(self, edge):
        self.list_edges_tree.append(edge)

    def get_list_edges_tree(self):
        return self.list_edges_tree


class Graph:
    def __init__(self):
        self._list_edges_graph = []
        self._set_adjacency_list = True
        self._kraskal_tree = Tree()
        self._prima_tree = Tree()
        self.adjacency_list = []
        self.data_list = []
        self.count_edges_ost = 0

    def set_adjacency_list(self, adjacency_list, data_list):
        self.adjacency_list = adjacency_list
        self.data_list = data_list
        self.count_edges_ost = len(self.adjacency_list)-1

        try:
            index_data = 0
            for from_node in range(len(adjacency_list)):
                for to in adjacency_list[from_node]:
                    data = self.data_list[index_data]
                    self._list_edges_graph.append(Edge(from_node, to, data))
                    index_data += 1
            if not Graph.__check_connect(adjacency_list, self._list_edges_graph):
                self._set_adjacency_list = False
                return 0
        except IndexError:
            self._set_adjacency_list = False
            return 0

    @staticmethod
    def __check_connect(adjacency_list, edges):
        node_visit = {edges[0].from_node, edges[0].to}
        for count in range(len(adjacency_list)):
            for edge in edges:
                if edge.from_node in node_visit or edge.to in node_visit:
                    node_visit.add(edge.from_node)
                    node_visit.add(edge.to)
        if len(node_visit) != len(adjacency_list):
            return 0
        return 1

    def get_list_edges_graph(self):
        return self._list_edges_graph

    def tree_prima(self):

        # Если список смежности установлен
        if self._set_adjacency_list:
            edges = self._list_edges_graph
            node_visit = set()

            # Выбрать случайную вершину и добавить её в список посещенных
            node_visit.add(randint(0, len(self.adjacency_list)-1))

            # Пока не посетим все вершины
            while len(node_visit) != len(self.adjacency_list):

                # Выбрать минимальное ребро
                min_edge = Graph.__return_min_edge(edges, node_visit)

                # Добавить минимальное ребро в дерево
                self._prima_tree.append_edge(min_edge)
            return self._prima_tree.list_edges_tree
        return 0

    def tree_kraskal(self):

        # Если список смежности установлен
        if self._set_adjacency_list:
            node_visit = set()
            edges = sorted(self._list_edges_graph, key=Graph.__compare)
            grupp_nodes = Graph.__make_grupps_nodes(edges)

            # Найти деревья с минимальным весом
            Graph.__first_pass(self, edges, node_visit)

            # Объединить эти деревья в одно остовное дерево
            Graph.__second_pass(self, edges, grupp_nodes)
            return self._kraskal_tree.list_edges_tree
        return 0

    def print_tree_kraskal(self):
        tree = ""
        for edge in self._kraskal_tree.list_edges_tree:
            tree += f'{edge.from_node}---{edge.to}  {edge.data}' + '\n'
        print(tree)

    def print_tree_prima(self):
        tree = ""
        for edge in self._prima_tree.list_edges_tree:
            tree += f'{edge.from_node}---{edge.to}  {edge.data}' + '\n'
        print(tree)

    @staticmethod
    def __compare(edge):
        return edge.data

    @staticmethod
    def __return_min_edge(edges, node_visit):
        array_edges = []

        for edge in edges:

            # Если одна из вершин есть в списке посещённых
            if (edge.from_node in node_visit
                    or edge.to in node_visit):

                # Если одной из вершин нет в списке посещённых
                if (edge.from_node not in node_visit
                        or edge.to not in node_visit):

                    # Добавить ребро в список
                    array_edges.append(edge)

        # Выбрать минимальное ребро из списка
        min_edge = min(array_edges, key=Graph.__compare)

        # Очистить список ребер
        array_edges.clear()

        # Добавить вершины минимального ребра в список посещённых
        node_visit.add(min_edge.from_node)
        node_visit.add(min_edge.to)
        return min_edge

    def __first_pass(self, edges, node_visit):
        for edge in edges:

            # Если обеих вершин нет в списке посещенных
            if (edge.from_node not in node_visit
                    and edge.to not in node_visit):

                # Добавить ребро в дерево
                self._kraskal_tree.append_edge(edge)

                # Добавить вершины в список посещенных
                node_visit.add(edge.to)
                node_visit.add(edge.from_node)

            # Иначе если одной из вершин нет в списке посещенных
            elif (edge.from_node not in node_visit
                  or edge.to not in node_visit):

                # Добавить ребро в дерево
                self._kraskal_tree.append_edge(edge)

                # Если первой вершины нет в списке посещённых
                if edge.from_node not in node_visit:

                    # Добавить первую вершину в список посещенных
                    node_visit.add(edge.from_node)

                # Если второй вершины нет в списке посещенных
                else:

                    # Добавить вторую вершину в список посещенных
                    node_visit.add(edge.to)

    def __second_pass(self, edges, grupp_nodes):
        for edge in edges:
            grupp_from = grupp_nodes[edge.from_node]
            grupp_to = grupp_nodes[edge.to]

            # Если количество вершин дерева не равно количеству вершин графа
            if len(self._kraskal_tree.list_edges_tree) != self.count_edges_ost:

                # Если первой вершины нет в группе второй
                #      и второй вершины нет в группе первой
                if (edge.from_node not in grupp_to
                        and edge.to not in grupp_from):

                    # Добавить ребро в дерево
                    self._kraskal_tree.append_edge(edge)

                # Объединить группы вершин
                grupp_nodes[edge.from_node] = grupp_to | grupp_from
                grupp_nodes[edge.to] = grupp_from

    @staticmethod
    def __make_grupp(edge, grupp_nodes):
        grupp_nodes[edge.from_node] = {edge.to, edge.from_node}
        grupp_nodes[edge.to] = {edge.from_node, edge.to}

    @staticmethod
    def __add_node_in_grupp(node1, node2, grupp_nodes):
        grupp_nodes[node2].add(node1)
        grupp_nodes[node1] = grupp_nodes[node2]

    @staticmethod
    def __make_grupps_nodes(edges):
        node_visit = set()
        grupp_nodes = {}

        for edge in edges:

            # Если обеих вершин нет в списке посещенных
            if (edge.from_node not in node_visit
                    and edge.to not in node_visit):

                # Создать группы для вершин
                Graph.__make_grupp(edge, grupp_nodes)

                # Добавить вершины в список посещённых
                node_visit.add(edge.from_node)
                node_visit.add(edge.to)

            # Иначе если одной из вершин нет в списке посещенных
            elif (edge.from_node not in node_visit
                    or edge.to not in node_visit):

                # Если первой вершины нет в списке посещенных
                if edge.from_node not in node_visit:

                    # Добавить первую вершину в группу
                    Graph.__add_node_in_grupp(edge.from_node, edge.to, grupp_nodes)

                    # Добавить первую вершину в список посещённых
                    node_visit.add(edge.from_node)

                # Если второй вершины нет в списке посещённых
                else:

                    # Добавить вторую вершину в группу
                    Graph.__add_node_in_grupp(edge.to, edge.from_node, grupp_nodes)

                    # Добавить вторую вершину в список посещённых
                    node_visit.add(edge.to)
        return grupp_nodes


