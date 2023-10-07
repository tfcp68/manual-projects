from MST_Graph import Graph

list_adjacency = [[1], [0, 2], [1]]
list_data = [1, 1, 2]
graph = Graph(list_adjacency, list_data)
graph.tree_kraskal()
graph.tree_prima()
graph.print_tree_kraskal()
print("________________")
graph.print_tree_prima()




