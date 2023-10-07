class Edge:
    def __init__(self, from_node, to, data):
        self.from_node = from_node
        self.to = to
        self.data = data


def set_adjacency_list(adjacency_list, data_list):
    try:
        edges_graph = list()
        index_data = 0
        for from_node in range(len(adjacency_list)):
            for to in adjacency_list[from_node]:
                data = data_list[index_data]
                edges_graph.append(Edge(from_node, to, data))
                index_data += 1
        return 'Некорректные данные.' if not len(adjacency_list) else len(adjacency_list)
    except IndexError:
        return 'Некорректные данные.'
