#include <vector>
#include <iostream>

const int INF = 1e9;

void return_way(int mask, int last, 
                std::vector<std::vector<int>> path, std::vector<int> &way) {
    if (mask == 0) {
        return;
    }
    return_way(mask - (1 << last), path[mask][last], path, way);
    way.push_back(last + 1);
    return;
}


std::pair<int, std::vector<int>> find_last_city(std::vector<std::vector<int>> min_path, int cnt_nodes, 
                                                std::vector<std::vector<int>> path) {
    int last_node = 0;
    int len_way = 0;
    std::vector<int> way;

    for (int node = 1; node < cnt_nodes; node++) {
        if (min_path[(1 << cnt_nodes) - 1][node] < min_path[(1 << cnt_nodes) - 1][last_node]) {
            last_node = node;
        }
    }
    len_way = min_path[(1 << cnt_nodes) - 1][last_node];
    if (len_way == INF) {
        len_way = 0;
    }
    return_way((1 << cnt_nodes) - 1, last_node, path, way);
    return { len_way, way };
}


std::pair<int, std::vector<int>> tsp(int cnt_nodes, std::vector<std::vector<int>> graph) {
    std::vector<std::vector<int>> min_path, path;
    for (int i = 0; i < (1 << cnt_nodes); i++) {
        min_path.push_back(std::vector<int>(cnt_nodes, 0));
        path.push_back(std::vector<int>(cnt_nodes, 0));
    }

    for (int mask = 1; mask < (1 << cnt_nodes); mask++) {
        for (int node = 0; node < cnt_nodes; node++) {
            if (mask == (1 << node)) {
                min_path[mask][node] = 0;
            }
            min_path[mask][node] = INF;
            if (mask & (1 << node)) {
                int pm = mask - (1 << node);

                for (int next_node = 1; next_node < cnt_nodes; next_node++) {
                    if (min_path[pm][next_node] + graph[next_node][node] < min_path[mask][node]) {
                        min_path[mask][node] = min_path[pm][next_node] + graph[next_node][node];
                        path[mask][node] = next_node;
                    }
                }
            }
        }
    }
    return find_last_city(min_path, cnt_nodes, path);
}

