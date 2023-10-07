#include "Graph.h"
#include "Tree.h"
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

bool Graph::set_adjacency_list(vector <vector <int>> adjacency_list, vector <float> data_list) {
    if ((adjacency_list.empty() != true) && (data_list.empty() != true)) {
        count_nodes_graph = adjacency_list.size();
        count_nodes_ost = count_nodes_graph - 1;
        size_t index_data = 0;
        for (int from = 0; from < count_nodes_graph; from++) {
            for (int to : adjacency_list[from]) {
                float data;
                if (index_data < data_list.size()) {
                    data = data_list[index_data];
                    list_edges_graph.push_back(Edge(from, to, data));
                    index_data++;
                }
                else {
                    return false;
                }
            };
        };
        if (check_connect(adjacency_list, list_edges_graph)) {
            adjacency_list_is_set = true;
        }
        return false;
    }
    return false;
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
        set <int> node_visit;
        vector <Edge> edges = list_edges_graph;
        sort(edges.begin(), edges.end(), compare);
        map <int, set <int>> grupp_nodes = make_grupps_nodes(edges);

        // Найти деревья с минимальным весом
        first_pass(edges, node_visit);

        // Объединить их в одно остовное дерево
        second_pass(edges, grupp_nodes);
        return kraskal_tree.list_edges_tree;
    }
    return null_vector;
}

void Graph::first_pass(vector <Edge> edges, set <int> node_visit) {
    for (Edge edge : edges) {

        // Если обеих вершин нет в списке посещенных
        if ((node_visit.count(edge.from) == 0) && (node_visit.count(edge.to) == 0)) {

            // Добавить ребро в дерево
            kraskal_tree.append_edge(edge);

            // Добавить ребро в дерево
            node_visit.insert(edge.from);
            node_visit.insert(edge.to);
        }

        // Иначе если одной из вершин нет в списке посещенных
        else if ((node_visit.count(edge.from) == 0) || (node_visit.count(edge.to) == 0)) {

            // Если первой вершины нет в списке посещённых
            if (node_visit.count(edge.from) == 0) {

                // Добавить ребро в дерево
                kraskal_tree.append_edge(edge);

                // Добавить первую вершину в список посещенных
                node_visit.insert(edge.from);
            }

            // Если второй вершины нет в списке посещенных
            else {

                // Добавить ребро в дерево
                kraskal_tree.append_edge(edge);

                // Добавить вторую вершину в список посещенных
                node_visit.insert(edge.to);
            }
        }
    };
}

void Graph::second_pass(vector <Edge> edges, map<int, set <int>> grupp_nodes) {
    for (Edge edge : edges) {

        // Если количество вершин дерева не равно количеству вершин графа 
        if (kraskal_tree.list_edges_tree.size() != count_nodes_ost) {

            // Если первой вершины нет в группе второй и второй вершины нет в группе первой
            if (grupp_nodes[edge.to].count(edge.from) == 0
                    && grupp_nodes[edge.from].count(edge.to) == 0) {

                // Добавить ребро в дерево
                kraskal_tree.append_edge(edge);
            }
        }

        // Объединить группы вершин
        set <int> grupp_from = grupp_nodes[edge.from];
        set <int> grupp_to = grupp_nodes[edge.to];
        set <int> grupp_union;
        merge(grupp_from.begin(), grupp_from.end(),
              grupp_to.begin(), grupp_to.end(),
              inserter(grupp_union, grupp_union.begin()));
        grupp_nodes[edge.from] = grupp_union;
        grupp_nodes[edge.to] = grupp_union;
    };
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


map <int, set <int>> Graph::make_grupps_nodes(vector <Edge> edges) {
    set <int> node_visit;
    map <int, set <int>>  grupp_nodes;
    for (Edge edge : edges) {

        // Если обеих вершин нет в списке посещенных
        if ((node_visit.count(edge.from) == 0) && (node_visit.count(edge.to) == 0)) {

            // Создать группы для вершин
            grupp_nodes[edge.from] = { edge.from, edge.to };
            grupp_nodes[edge.to] = { edge.from, edge.to };

            // Добавить вершины в список посещённых
            node_visit.insert(edge.from);
            node_visit.insert(edge.to);
        }

        // Иначе если одной из вершин нет в списке посещенных
        else if ((node_visit.count(edge.from) == 0) || (node_visit.count(edge.to) == 0)) {

            // Если первой вершины нет в списке посещенных  
            if (node_visit.count(edge.from) == 0) {

                // Добавить первую вершину в группу
                grupp_nodes[edge.to].insert(edge.from);
                grupp_nodes[edge.from] = grupp_nodes[edge.to];

                // Добавить первую вершину в список посещённых
                node_visit.insert(edge.from);
            }

            // Если второй вершины нет в списке посещённых
            else {
                // Добавить вторую вершину в группу
                grupp_nodes[edge.from].insert(edge.to);
                grupp_nodes[edge.to] = grupp_nodes[edge.from];

                // Добавить вторую вершину в список посещённых
                node_visit.insert(edge.to);
            }
        }
    };
    return grupp_nodes;
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