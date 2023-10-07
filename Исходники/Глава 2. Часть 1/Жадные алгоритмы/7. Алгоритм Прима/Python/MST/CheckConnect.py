def check_connect(adjacency_list, edges):
    node_visit = {edges[0].from_node, edges[0].to}
    for count in range(len(adjacency_list)):
        for edge in edges:
            if edge.from_node in node_visit or edge.to in node_visit:
                node_visit.add(edge.from_node)
                node_visit.add(edge.to)
    if len(node_visit) != len(adjacency_list):
        return False
    return True
