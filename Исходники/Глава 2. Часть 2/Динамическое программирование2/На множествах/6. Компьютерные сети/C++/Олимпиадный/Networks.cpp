#include<vector>
#include <iostream>


int count_computers(std::vector<std::vector<int>> graph, int size_graph) {
	int node_from_set = 0;
	std::vector<int> sets(1 << size_graph, 0);

    // Цикл по множествам
    for (int set = 1; set < (1 << size_graph); set++) {

        // Цикл по вершинам множества
        for (int node = 0; node < size_graph; node++) {

            // Выбираем вершину которая принадлежит множеству
            if (set & (1 << node)) {
                node_from_set = node;
                break;
            }
        }
        // Если вершина свободна
        sets[set] = sets[set - (1 << node_from_set)];

        // Цикл по всем вершинам от node_from_set
        for (int node = node_from_set + 1; node < size_graph; node++) {

            // Если вершина из множества связана с другой вершиной
            if (graph[node_from_set][node] == 1 and (set & (1 << node))) {
                int curr_count_computer = sets[set - (1 << node_from_set) - (1 << node)] + 1;

                sets[set] = std::max(curr_count_computer, sets[set]);
            }
        }
    }
	return sets[(1 << size_graph) - 1] * 2;
}