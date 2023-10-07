#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>
#include <map>
#include <set>
#include "Edge.h"

bool set_adjacency_list(std::vector<std::vector<int>> adjacency_list, std::vector<float> data_list);
bool check_connect(std::vector <std::vector <int>> adjacency_list, std::vector <Edge> edges);
std::map <int, std::set <int>> make_grupps_nodes(std::vector <Edge> edges);
bool compare(Edge edge1, Edge edge2);
Edge return_min_edge(std::vector <Edge> edges, std::set <int> node_visit);
std::vector<std::vector<int>> random_adjacency_list(std::vector<std::vector<int>> matrix);
std::vector<std::vector<int>> random_matrix(int count_nodes);
std::vector<float> random_data_list(std::vector<std::vector<int>> matrix);
bool this_tree_or_not(int start_node, std::vector<std::vector<int>> list_adjacency);
std::vector<std::vector<int>> make_list_adjacency_tree(std::vector<Edge> edges);

#endif