#ifndef TREE_H
#define TREE_H

#include "Edge.h"
#include <vector>

using namespace std;

class Tree {
public:
    vector <Edge> list_edges_tree;
    void append_edge(Edge edge);
    vector <Edge> get_list_edges_tree();
};

#endif