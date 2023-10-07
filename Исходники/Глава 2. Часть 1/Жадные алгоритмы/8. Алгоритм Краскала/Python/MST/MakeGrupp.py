
def make_grupps_nodes(edges):
    node_visit = set()
    grupp_nodes = {}

    for edge in edges:
        if (edge.from_node not in node_visit
                and edge.to not in node_visit):
            grupp_nodes[edge.from_node] = set([edge.to, edge.from_node])
            grupp_nodes[edge.to] = set([edge.from_node, edge.to])
            node_visit.add(edge.from_node)
            node_visit.add(edge.to)

        elif (edge.from_node not in node_visit
                or edge.to not in node_visit):
            if edge.from_node not in node_visit:
                grupp_nodes[edge.to].add(edge.from_node)
                grupp_nodes[edge.from_node] = grupp_nodes[edge.to]
                node_visit.add(edge.from_node)
            else:
                grupp_nodes[edge.from_node].add(edge.to)
                grupp_nodes[edge.to] = grupp_nodes[edge.from_node]
                node_visit.add(edge.to)
    return grupp_nodes

def compare(edge):
    return edge.data


