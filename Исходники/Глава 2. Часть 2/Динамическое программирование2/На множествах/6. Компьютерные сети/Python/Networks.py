

def count_computers(graph, n):
    i = 0
    f = [0] * (1 << n)

    # Цикл по множествам
    for mask in range(1, 1 << n):

        # Цикл по вершинам множества
        for j in range(0, n):

            # Выбираем вершину i, которая принадлежит множеству mask
            if mask & (1 << j):
                i = j
                break

        # Если i-ая свободна
        f[mask] = f[mask - (1 << i)]

        # Цикл по всем вершинам без i
        for j in range(i + 1, n):

            # Если i-тая вершина связана с j-ой вершиной
            if graph[i][j] == 1 and (mask & (1 << j)):
                k = f[mask - (1 << i) - (1 << j)] + 1

                f[mask] = max(k, f[mask])

    return f[(1 << n) - 1] * 2


#  ++c ______________________________________ c++


# int count_computers(std::vector<std::vector<int>> graph, int size_graph) {
#     int node_from_set = 0;
#     std::vector<int> sets(1 << size_graph, 0);
#
#     // Цикл по множествам
#     for (int set = 1; set < (1 << size_graph); set++) {
#
#         // Цикл по вершинам множества
#         for (int node = 0; node < size_graph; node++) {
#
#             // Выбираем вершину которая принадлежит множеству
#             if (set & (1 << node)) {
#                 node_from_set = node;
#                 break;
#             }
#         }
#         // Если вершина свободна
#         sets[set] = sets[set - (1 << node_from_set)];
#
#         // Цикл по всем вершинам от node_from_set
#         for (int node = node_from_set + 1; node < size_graph; node++) {
#
#             // Если вершина из множества связана с другой вершиной
#             if (graph[node_from_set][node] == 1 and (set & (1 << node))){
#                 int curr_count_computer = sets[set - (1 << node_from_set) - (1 << node)] + 1;
#
#                 sets[set] = std::max(curr_count_computer, sets[set]);
#             }
#         }
#     }
#     return sets[(1 << size_graph) - 1] * 2;
# }
