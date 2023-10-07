#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>

#include "Graph_MST.h"

int main() {
    vector <vector<int>> list = { {1, 2}, {0, 3}, {0, 5, 4}, {1, 4, 5}, {2, 3}, {2, 3}, {} };
    vector <float> data_list = { 1, 5, 1, 3, 6, 7, 1, 3, 6, 11, 1, 6, 7, 11 };
    Graph graph;
    graph.set_adjacency_list(list, data_list);

    cout << "_______" << endl;
    vector <Edge> bb = graph.tree_prima();
    for (Edge b : bb) {
        cout << b.data << endl;
    };

    cout << "_______" << endl;
    vector <Edge> cc = graph.tree_kraskal();
    for (Edge c : cc) {
        cout << c.data << endl;
    };

    return 0;
}