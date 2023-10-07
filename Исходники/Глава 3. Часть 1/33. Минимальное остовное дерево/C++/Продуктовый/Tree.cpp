#include "Tree.h"
#include "Edge.h"
#include <iostream>
#include <vector>

using std::vector;

void Tree::append_edge(Edge edge) {
    list_edges_tree.push_back(edge);
}

vector <Edge> Tree::get_list_edges_tree() {
    return list_edges_tree;
}

