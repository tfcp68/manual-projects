#ifndef GRAPH_H
#define GRAPH_H

#include "Edge.h"
#include "Tree.h"
#include <vector>
#include <map>
#include <set>

using namespace std;

class Graph {
public:
    bool set_adjacency_list(vector <vector <int>> adjacency_list, vector <float> data_list);
    vector <Edge> tree_prima();
    vector <Edge> tree_kraskal();
    vector <Edge> get_list_edges_graph();
private:
    bool adjacency_list_is_set = false;
    int count_nodes_graph;
    int count_nodes_ost;
    vector <Edge> list_edges_graph;
    Tree prima_tree;
    Tree kraskal_tree;
    void first_pass(vector <Edge> edges, set <int> node_visit);
    void second_pass(vector <Edge> edges, map<int, set <int>> grupp_nodes);
    int get_random_node();
    static bool compare(Edge edge1, Edge edge2);
    static Edge return_min_edge(vector <Edge> edges, set <int> node_visit);
    static map <int, set <int>> make_grupps_nodes(vector <Edge> edges);
    bool check_connect(vector <vector <int>> adjacency_list, vector <Edge> edges);
};

#endif