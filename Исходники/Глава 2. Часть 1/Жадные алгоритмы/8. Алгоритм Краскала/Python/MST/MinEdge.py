def compare(edge):
        return edge.data

def return_min_edge(edges, node_visit):
        array_edges = []
        for edge in edges:
            if (edge.from_node in node_visit or edge.to in node_visit):
                if (edge.from_node not in node_visit or
                    edge.to not in node_visit):
                    array_edges.append(edge)

        min_edge = min(array_edges, key=compare)
        array_edges.clear()
        node_visit.add(min_edge.from_node)
        node_visit.add(min_edge.to)
        return min_edge

