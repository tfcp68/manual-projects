#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <ctime>

using namespace std;

struct Edge {
    int from;
    int to;
    float data;

    Edge(int set_from, int set_to, float set_data) {
        from = set_from;
        to = set_to;
        data = set_data;
    }
};

class Tree {
public:
    vector <Edge> list_edges_tree;

    void append_edge(Edge edge) {
        list_edges_tree.push_back(edge);
    };

    vector <Edge> get_list_edges_tree() {
        return list_edges_tree;
    };
};

class Graph {
public:
    void set_adjacency_list(vector <vector <int>> adjacency_list, vector <float> data_list) {
            int index_data = 0;
            count_nodes_graph = adjacency_list.size();
            count_nodes_ost = count_nodes_graph - 1;
            for (int from = 0; from < count_nodes_graph; from++) {
                for (int to : adjacency_list[from]) {
                    float data;
                    data = data_list[index_data];
                    list_edges_graph.push_back(Edge(from, to, data));
                    index_data++;
                };
            };
        };

    vector <Edge> tree_prima() {
        vector <Edge> edges = list_edges_graph;
        set <int> node_visit;
        node_visit.insert(get_random_node());
        while (node_visit.size() != count_nodes_graph) {
            Edge min_edge = return_min_edge(edges, node_visit);
            prima_tree.append_edge(min_edge);
            node_visit.insert(min_edge.from);
            node_visit.insert(min_edge.to);
        };
        return prima_tree.get_list_edges_tree();
    };

    vector <Edge> tree_kraskal() {
        int vertex = count_nodes_graph;
        UnionFind group_nodes(vertex);
        vector <Edge> edges = list_edges_graph;
        sort(edges.begin(), edges.end(), compare);
        for (Edge edge : edges) {
            if (!group_nodes.same_set(edge.from, edge.to)) {
                kraskal_tree.append_edge(edge);
                group_nodes.union_set(edge.from, edge.to);
            }
        }
        return kraskal_tree.list_edges_tree;
    };

private:
    int count_nodes_graph;
    int count_nodes_ost;
    vector <Edge> list_edges_graph;
    Tree prima_tree;
    Tree kraskal_tree;

    int get_random_node() {
        srand(time(0));
        int random_node = rand() % count_nodes_graph;
        return random_node;
    };

    static bool compare(Edge edge1, Edge edge2) {
        return edge1.data < edge2.data;
    };

    static Edge return_min_edge(vector <Edge> edges, set <int> node_visit) {
        vector <Edge> vector_edges;
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
    };

};

int main() {
    vector <vector<int>> list = { {1, 2}, {0, 3}, {0, 5, 4}, {1, 4, 5}, {2, 3}, {2, 3} };
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