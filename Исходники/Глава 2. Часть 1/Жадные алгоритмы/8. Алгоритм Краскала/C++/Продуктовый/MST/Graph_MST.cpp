#include "Graph_MST.h"
#include "Tree.h"
#include "UnionFind.h"

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

void Graph::set_adjacency_list(vector <vector <int>> adjacency_list, vector <float> data_list) {
    if ((adjacency_list.empty() != true) && (data_list.empty() != true)) {
        count_nodes_graph = adjacency_list.size();
        size_t index_data = 0;
        float data;
        for (int from = 0; from < count_nodes_graph; from++) {
            for (int to : adjacency_list[from]) {
                if (index_data < data_list.size()) {
                    data = data_list[index_data];
                    list_edges_graph.push_back(Edge(from, to, data));
                    index_data++;
                } 
            };
        };
        if (check_connect(adjacency_list, list_edges_graph)) {
            adjacency_list_is_set = true;
        } 
    }
}

vector <Edge> Graph::get_list_edges_graph() {
    return list_edges_graph;
}

vector <Edge> Graph::tree_prima() {
    vector <Edge> null_vector;

    // Если список смежности установлен
    if (adjacency_list_is_set) {
        vector <Edge> edges = list_edges_graph;
        set <int> node_visit;

        // Выбрать случайную вершину и добавить в список посещённых
        node_visit.insert(get_random_node());

        // Пока не посетим все вершины
        while (node_visit.size() != count_nodes_graph) {

            // Выбрать минимальное ребро
            Edge min_edge = return_min_edge(edges, node_visit);

            // Добавить минимальное ребро в дерево
            prima_tree.append_edge(min_edge);

            // Добавить вершины в список посещенных
            node_visit.insert(min_edge.from);
            node_visit.insert(min_edge.to);
        };
        return prima_tree.get_list_edges_tree();
    }
    return null_vector;
}

vector <Edge> Graph::tree_kraskal() {
    vector <Edge> null_vector;

    // Если список смежности установлен
    if (adjacency_list_is_set) {
        int vertex = count_nodes_graph;
        UnionFind group_nodes(vertex);
        vector <Edge> edges = list_edges_graph;

        // Сортировать ребра по возрастанию
        sort(edges.begin(), edges.end(), compare);
        for (Edge edge : edges) {

            // Если вершины из разных групп
            if (!group_nodes.same_set(edge.from, edge.to)) {

                // Добавляем ребро в дерево
                kraskal_tree.append_edge(edge);

                // Объединяем группы вершин
                group_nodes.union_set(edge.from, edge.to);
            }
        }
        return kraskal_tree.list_edges_tree;
    }
    return null_vector;
}

int Graph::get_random_node() {
    srand(time(0));
    int random_node = rand() % count_nodes_graph;
    return random_node;
}

bool Graph::compare(Edge edge1, Edge edge2) {
    return edge1.data < edge2.data;
}

Edge Graph::return_min_edge(vector <Edge> edges, set <int> node_visit) {
    vector <Edge> vector_edges;
    for (Edge edge : edges) {

        // Если одна из вершин есть в списке посещённых
        if ((node_visit.count(edge.from) != 0) || (node_visit.count(edge.to) != 0)) {

            // Если одной из вершин нет в списке посещённых
            if ((node_visit.count(edge.from)) == 0 || (node_visit.count(edge.to)) == 0) {

                // Добавить ребро в список 
                vector_edges.push_back(edge);
            }
        }
    };

    // Сортировать список ребер по возрастанию весов 
    sort(vector_edges.begin(), vector_edges.end(), compare);

    // Взять минимальное ребро из списка
    Edge min_edge = vector_edges[0];

    // Очистить список ребер
    vector_edges.clear();
    return min_edge;
}

bool Graph::check_connect(vector <vector <int>> adjacency_list, vector <Edge> edges) {
    set <int> node_visit = { edges[0].from, edges[0].to };
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