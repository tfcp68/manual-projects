#ifndef GRAPH_MST_H
#define GRAPH_MST_H

#include "Edge.h"
#include "Tree.h"
#include <vector>
#include <set>

using namespace std;

class Graph {
public:
    void set_adjacency_list(vector<vector<int>> adjacency_list, vector<float> data_list);
    vector<Edge> tree_prima();
    vector<Edge> tree_kraskal();
    vector<Edge> get_list_edges_graph();
private:
    bool adjacency_list_is_set = false;
    size_t count_nodes_graph = 0;
    vector<Edge> list_edges_graph;
    Tree prima_tree;
    Tree kraskal_tree;
    int get_random_node();
    static bool compare(Edge edge1, Edge edge2);
    static Edge return_min_edge(vector<Edge> edges, set<int> node_visit);
    bool check_connect(vector<vector<int>> adjacency_list, vector<Edge> edges);
};

#endif