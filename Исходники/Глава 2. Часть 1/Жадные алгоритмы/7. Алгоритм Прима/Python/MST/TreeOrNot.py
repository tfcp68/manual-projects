def this_tree_or_not(start_node, list_adjacency):
    node_visited = []
    queue = []
    nodes = []

    queue.append(start_node)
    node_visited.append(start_node)
    while queue:
        start_node = queue.pop(0)
        if start_node not in nodes:
            nodes.append(start_node)
            for neighbor in list_adjacency[start_node]:
                if neighbor not in node_visited:
                    queue.append(neighbor)
                    node_visited.append(start_node)
        else:
            return 0
    return 1

def make_list_adjacency_tree(edges):
    nodes = set()
    for edge in edges:
        nodes.add(edge.from_node)
        nodes.add(edge.to)
    list_adjacency = [[] for _ in range(len(nodes))]

    for node in nodes:
        for edge in edges:
            if node == edge.from_node:
                list_adjacency[node].append(edge.to)
    return list_adjacency