#include <vector>
#include <set>
#include <algorithm>
#include <ctime>
#include <queue>

#include "Edge.h"

bool set_adjacency_list(std::vector<std::vector<int>> adjacency_list, std::vector<float> data_list) {
    std::vector<Edge> list_edges_graph;
    if ((adjacency_list.empty() != true) && (data_list.empty() != true)) {
        size_t count_nodes_graph = adjacency_list.size();
        size_t index_data = 0;
        for (int from = 0; from < count_nodes_graph; from++) {
            for (int to : adjacency_list[from]) {
                float data;
                if (index_data < data_list.size()) {
                    data = data_list[index_data];
                    list_edges_graph.push_back(Edge(from, to, data));
                    index_data++;
                } else { return false; }
            };
        };return true;
      
    } else { return false; }
}

bool check_connect(std::vector <std::vector <int>> adjacency_list, std::vector <Edge> edges) {
    std::set <int> node_visit = { edges[0].from, edges[0].to };
    for (int count = 0; count < adjacency_list.size(); count++) {
        for (Edge edge : edges) {
            if ((node_visit.count(edge.from) != 0) || (node_visit.count(edge.to) != 0)) {
                node_visit.insert(edge.from);
                node_visit.insert(edge.to);
            }
        }
    }
    if (node_visit.size() != adjacency_list.size()) {
        return false;
    }
    return true;
}

bool compare(Edge edge1, Edge edge2) {
    return edge1.data < edge2.data;
}


Edge return_min_edge(std::vector <Edge> edges, std::set <int> node_visit) {
    std::vector <Edge> vector_edges;
    for (Edge edge : edges) {
        if ((node_visit.count(edge.from) != 0) || (node_visit.count(edge.to) != 0)) {
            if ((node_visit.count(edge.from)) == 0 || (node_visit.count(edge.to)) == 0) {
                vector_edges.push_back(edge);
            }
        }
    };
    sort(vector_edges.begin(), vector_edges.end(), compare);
    Edge min_edge = vector_edges[0];
    vector_edges.clear();
    return min_edge;
}


std::vector<std::vector<int>> random_matrix(int count_nodes) {
    std::vector<std::vector<int>> matrix;
    std::vector<int> from_vector;
    for (int from_node = 0; from_node < count_nodes; from_node++) {
        matrix.push_back(from_vector);
    };
    srand(time(0));
    for (int from = 0; from < count_nodes; from++) {
        for (int to = 0; to < count_nodes; to++) {
            matrix[from].push_back(rand() % 2);
        };
    };
    for (int from = 0; from < matrix.size(); from++) {
        for (int to = 0; to < matrix[from].size(); to++) {
            matrix[from][to] = matrix[to][from];
            if (from == to) {
                matrix[from][to] = 0;
            }
        };
    };
    return matrix;
}


std::vector<std::vector<int>> random_adjacency_list(std::vector<std::vector<int>> matrix) {
    std::vector<std::vector<int>> adjacency_list;

    std::vector<int> from_vector;
    for (int from_node = 0; from_node < matrix.size(); from_node++) {
        adjacency_list.push_back(from_vector);
    };

    for (int from = 0; from < matrix.size(); from++) {
        for (int to = 0; to < matrix[from].size(); to++) {
            if (matrix[from][to]) {
                adjacency_list[from].push_back(to);
            }
        };
    };
    return adjacency_list;
}


std::vector<float> random_data_list(std::vector<std::vector<int>> matrix) {
    srand(time(0));
    std::vector<float> data_list;
    for (int from = 0; from < matrix.size(); from++) {
        for (int to = 0; to < matrix[from].size(); to++) {
            float data = rand() % 50;
            if (matrix[from][to]) {
                matrix[from][to] = data;
                matrix[to][from] = data;
            }
        }
    }
    for (int from = 0; from < matrix.size(); from++) {
        for (int to = 0; to < matrix[from].size(); to++) {
            if (matrix[from][to] != 0) {
                data_list.push_back(matrix[from][to]);
            }
        }
    }
    return data_list;
}


bool this_tree_or_not(int start_node, std::vector<std::vector<int>> list_adjacency) {
    std::set<int> node_visited;
    std::queue<int> queue_nodes;
    std::set<int> nodes;

    queue_nodes.push(start_node);
    node_visited.insert(start_node);
    while (queue_nodes.size() != 0) {
        int node = queue_nodes.front();
        queue_nodes.pop();
        if (nodes.count(node) == 0) {
            nodes.insert(node);
            for (int neighbor : list_adjacency[node]) {
                if (node_visited.count(neighbor) == 0) {
                    queue_nodes.push(neighbor);
                    node_visited.insert(node);
                }
            };
        }
        else {
            return false;
        }
    }
    return true;
}


std::vector<std::vector<int>> make_list_adjacency_tree(std::vector<Edge> edges) {
    std::vector<std::vector<int>> adjacency_list;
    std::set<int> nodes;
    for (Edge edge : edges) {
        nodes.insert(edge.from);
        nodes.insert(edge.to);
    };
    std::vector<int> from_vector;
    for (int from_node = 0; from_node < nodes.size(); from_node++) {
        adjacency_list.push_back(from_vector);
    };

    for (int node : nodes) {
        for (Edge edge : edges) {
            if (node == edge.from) {
                adjacency_list[node].push_back(edge.to);
            }
        };
    };
    return adjacency_list;
}