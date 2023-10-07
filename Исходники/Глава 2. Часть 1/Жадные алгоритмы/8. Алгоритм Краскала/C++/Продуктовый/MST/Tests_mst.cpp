#include "Functions.h"
#include "Graph_MST.h"

#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>

class TestSetAdjacencyList {
public:
    void test_1() {
        vector<vector<int>> list_adjacency = {};
        vector<float> list_data = { 1, 2, 3 };
        auto res = set_adjacency_list(list_adjacency, list_data);
        assert(res == false);
    };

    void test_2() {
        vector<vector<int>> list_adjacency = {};
        vector<float> list_data = { 1, 2, 0, 3, 0, 5, 4, 1, 4, 5, 2, 3, 2, 3 };
        auto res = set_adjacency_list(list_adjacency, list_data);
        assert(res == false);
    };

    void test_3() {
        vector<vector<int>> list_adjacency = {};
        vector<float> list_data = {};
        auto res = set_adjacency_list(list_adjacency, list_data);
        assert(res == false);
    };

    void test_4() {
        vector<vector<int>> list_adjacency = { {1, 2} };
        vector<float> list_data = {};
        auto res = set_adjacency_list(list_adjacency, list_data);
        assert(res == false);
    };

    void test_5() {
        vector<vector<int>> list_adjacency = {};
        vector<float> list_data = { 1 };
        auto res = set_adjacency_list(list_adjacency, list_data);
        assert(res == false);
    };

    void test_6() {
        vector<vector<int>> list_adjacency = { {1} };
        vector<float> list_data = { 1 };
        auto res = set_adjacency_list(list_adjacency, list_data);
        assert(res == true);
    };

    void test_7() {
        vector<vector<int>> list_adjacency = { {1}, {0} };
        vector<float> list_data = { 1, 2 };
        auto res = set_adjacency_list(list_adjacency, list_data);
        assert(res == true);
    };

    void test_8() {
        vector<vector<int>> list_adjacency = { {1, 2},{0, 2},{1, 0} };
        vector<float> list_data = { 1, 3, 4, 1, 2, 3 };
        auto res = set_adjacency_list(list_adjacency, list_data);
        assert(res == true);
    };

    void test_9() {
        vector<vector<int>> list_adjacency = { {1, 2},{3, 4},{2, 0} };
        vector<float> list_data = { 1, 3, 4, 1, 2, 5 };
        auto res = set_adjacency_list(list_adjacency, list_data);
        assert(res == true);
    };

    void  test_10() {
        vector<vector<int>>list_adjacency = { {1, 2},{3, 4},{2, 0},{1, 2, 4},{1},{1, 2, 3} };
        vector<float> list_data = { 1, 3, 4, 1, 2, 5, 1, 2, 4, 5, 7, 8, 9 };
        auto res = set_adjacency_list(list_adjacency, list_data);
        assert(res == true);
    };
};

class TestCheckConnect {
public:
    void test_1() {
        Graph graph;
        vector<vector<int>>adjacency_list = { {1, 2},{0, 3},{0, 3, 5 },{1, 2, 4},{3, 5},{2, 4} };
        vector<float>list_data = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
        graph.set_adjacency_list(adjacency_list, list_data);
        vector<Edge> edges = graph.get_list_edges_graph();
        auto res = check_connect(adjacency_list, edges);
        assert(res == true);
    };
    void test_2() {
        Graph graph;
        vector<vector<int>>adjacency_list = { {1, 2},
            {0, 3, 5},
            {0, 3, 4, 6},
            {1, 2, 6},
            {2},
            {1},
            {2, 3} };
        vector<float>list_data = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
        graph.set_adjacency_list(adjacency_list, list_data);
        vector<Edge> edges = graph.get_list_edges_graph();
        auto res = check_connect(adjacency_list, edges);
        assert(res == true);
    };
    void test_3() {
        Graph graph;
        vector<vector<int>>adjacency_list = { {1, 2},{0, 3},{0, 3},{1, 2},{5},{ 4 } };
        vector<float> list_data = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        graph.set_adjacency_list(adjacency_list, list_data);
        vector<Edge> edges = graph.get_list_edges_graph();
        auto res = check_connect(adjacency_list, edges);
        assert(res == false);
    };
    void test_4() {
        Graph graph;
        vector<vector<int>>adjacency_list = { {1, 2},{0, 3},{0, 3},{1, 2},{} };
        vector<float>list_data = { 1, 2, 3, 4, 5, 6, 7, 8 };
        graph.set_adjacency_list(adjacency_list, list_data);
        vector<Edge> edges = graph.get_list_edges_graph();
        auto res = check_connect(adjacency_list, edges);
        assert(res == false);
    };
    void test_5() {
        Graph graph;
        vector<vector<int>>adjacency_list = { {1, 2}, {0, 3}, {0, 3}, {1, 2}, {5, 6}, {4, 7}, {4, 7}, { 5, 6 } };
        vector<float> list_data = { 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8 };
        graph.set_adjacency_list(adjacency_list, list_data);
        vector<Edge> edges = graph.get_list_edges_graph();
        auto res = check_connect(adjacency_list, edges);
        assert(res == false);
    }
};

class TestReturnMinEdge {
public:
    void test_1() {
        Graph graph;
        vector<vector<int>> list_adjacency = { {1, 2},{0, 3},{0, 5, 4},{1, 4, 5},{2, 3},{2, 3} };
        vector<float> list_data = { 1, 5, 1, 3, 5, 7, 1, 3, 6, 11, 1, 6, 7, 11 };
        graph.set_adjacency_list(list_adjacency, list_data);
        set<int> node_visit;
        node_visit.insert(0);
        vector <Edge> edges = graph.get_list_edges_graph();
        Edge res = return_min_edge(edges, node_visit);
        assert(res.data == 1);
    };
    void test_2() {
        Graph graph;
        vector<vector<int>> list_adjacency = { {1, 2},{0, 3},{0, 4, 5},{1, 4, 5},{2, 3},{2, 3} };
        vector<float> list_data = { 1, 5, 1, 3, 5, 1, 1, 3, 7, 6, 1, 7, 1, 6 };
        graph.set_adjacency_list(list_adjacency, list_data);
        set<int> node_visit;
        node_visit.insert(0);
        node_visit.insert(1);
        vector <Edge> edges = graph.get_list_edges_graph();
        Edge res = return_min_edge(edges, node_visit);
        assert(res.data == 3);
    };
    void test_3() {
        Graph graph;
        vector<vector<int>> list_adjacency = { {1, 2},{0, 3},{0, 4, 5},{1, 4, 5},{2, 3},{2, 3} };
        vector<float>   list_data = { 1, 5, 1, 3, 5, 1, 1, 3, 7, 6, 1, 7, 1, 6 };
        graph.set_adjacency_list(list_adjacency, list_data);
        set<int> node_visit;
        node_visit.insert(5);
        vector <Edge> edges = graph.get_list_edges_graph();
        Edge res = return_min_edge(edges, node_visit);
        assert(res.data == 1);
    };
    void test_4() {
        Graph graph;
        vector<vector<int>> list_adjacency = { {1, 2},{0, 3},{0, 4, 5},{1, 4, 5},{2, 3},{2, 3} };
        vector<float>   list_data = { 1, 5, 1, 3, 5, 1, 1, 3, 7, 6, 1, 7, 1, 6 };
        graph.set_adjacency_list(list_adjacency, list_data);
        set<int> node_visit;
        node_visit.insert(2);
        vector <Edge> edges = graph.get_list_edges_graph();
        Edge res = return_min_edge(edges, node_visit);
        assert(res.data == 1);
    };
    void test_5() {
        Graph graph;
        vector<vector<int>> list_adjacency = { {1, 2},{0, 3},{0, 4, 5},{1, 4, 5},{2, 3},{2, 3},{3} };
        vector<float> list_data = { 1, 5, 1, 3, 5, 1, 1, 3, 7, 6, 1, 7, 1, 6, 2 };
        graph.set_adjacency_list(list_adjacency, list_data);
        set<int> node_visit;
        node_visit.insert(3);
        vector <Edge> edges = graph.get_list_edges_graph();
        Edge res = return_min_edge(edges, node_visit);
        assert(res.data == 2);
    };
    void test_6() {
        Graph graph;
        vector<vector<int>> list_adjacency = { {1, 2},{0, 3},{0, 4, 5},{1, 4, 5},{2, 3},{2, 3} };
        vector<float>  list_data = { 1, 5, 1, 3, 5, 1, 1, 3, 7, 6, 1, 7, 1, 6 };
        graph.set_adjacency_list(list_adjacency, list_data);
        set<int> node_visit;
        node_visit.insert(4);
        vector <Edge> edges = graph.get_list_edges_graph();
        Edge res = return_min_edge(edges, node_visit);
        assert(res.data == 1);
    };
};

class TestTreePrima {
public:
    void test_1() {
        Graph graph;
        vector<vector<int>> list_adjacency = { {1, 2},{0, 3},{0, 4, 5},{1, 4, 5},{2, 3}, {2, 3} };
        vector<float> list_data = { 1, 5, 1, 3, 5, 1, 1, 3, 7, 6, 1, 7, 1, 6 };
        graph.set_adjacency_list(list_adjacency, list_data);
        vector <float> data;
        vector <Edge> edges = graph.tree_prima();
        for (Edge edge : edges) {
            data.push_back(edge.data);
        };
        sort(data.begin(), data.end());
        vector<float> res_data = { 1, 1, 1, 3, 5 };
        assert(res_data == data);
    };

    void test_2() {
        Graph graph;
        vector<vector<int>> list_adjacency = { {1, 2, 6, 7},{0, 3, 6},{0, 4, 5, 7},{1, 4, 5},{2, 3}, {2, 3}, {0, 1, 7}, {0, 2, 6} };
        vector<float> list_data = { 1, 5, 1, 4, 1, 3, 7, 5, 1, 1, 2, 3, 7, 6, 1, 7, 1, 6, 1, 7, 3, 4, 2, 3 };
        graph.set_adjacency_list(list_adjacency, list_data);
        vector <float> data;
        vector <Edge> edges = graph.tree_prima();
        for (Edge edge : edges) {
            data.push_back(edge.data);
        };
        sort(data.begin(), data.end());
        vector<float> res_data = { 1, 1, 1, 1, 2, 3, 3 };
        assert(res_data == data);
    };

    void test_3() {
        Graph graph;
        vector<vector<int>> list_adjacency = { {2, 7},{3, 6},{0, 4, 5, 7},{1, 4, 5},{2, 3}, {2, 3}, {1, 7}, {0, 2, 6} };
        vector<float> list_data = { 5, 4, 3, 7, 5, 1, 1, 2, 3, 7, 6, 1, 7, 1, 6, 7, 3, 4, 2, 3 };
        graph.set_adjacency_list(list_adjacency, list_data);
        vector <float> data;
        vector <Edge> edges = graph.tree_prima();
        for (Edge edge : edges) {
            data.push_back(edge.data);
        };
        sort(data.begin(), data.end());
        vector<float> res_data = { 1, 1, 2, 3, 3, 4, 6 };
        assert(res_data == data);
    };

    void test_4() {
        Graph graph;
        vector<vector<int>> list_adjacency = { {2},{3, 6},{0, 4, 5, 7},{1, 4, 5},{2, 3},{2, 3}, {1, 7}, {2, 6} };
        vector<float> list_data = { 5, 3, 7, 5, 1, 1, 2, 3, 7, 6, 1, 7, 1, 6, 7, 3, 2, 3 };
        graph.set_adjacency_list(list_adjacency, list_data);
        vector <float> data;
        vector <Edge> edges = graph.tree_prima();
        for (Edge edge : edges) {
            data.push_back(edge.data);
        };
        sort(data.begin(), data.end());
        vector<float> res_data = { 1, 1, 2, 3, 3, 5, 6 };
        assert(res_data == data);
    };

    void test_5() {
        Graph graph;
        vector<vector<int>> list_adjacency = { {2, 5},{3, 5},{0, 4, 5},{1, 4, 5},{2, 3}, {0, 1, 2, 3} };
        vector<float> list_data = { 5, 2, 3, 7, 5, 1, 1, 3, 7, 6, 1, 7, 2, 7, 1, 6 };
        graph.set_adjacency_list(list_adjacency, list_data);
        vector <float> data;
        vector <Edge> edges = graph.tree_prima();
        for (Edge edge : edges) {
            data.push_back(edge.data);
        };
        sort(data.begin(), data.end());
        vector<float> res_data = { 1, 1, 2, 3, 6 };
        assert(res_data == data);
    };

    void test_6() {
        Graph graph;
        vector<vector<int>> list_adjacency = { {2, 5},{3, 5},{0, 5},{1, 4, 5},{3}, {0, 1, 2, 3} };
        vector<float> list_data = { 5, 2, 3, 7, 5, 1, 3, 7, 6, 7, 2, 7, 1, 6 };
        graph.set_adjacency_list(list_adjacency, list_data);
        vector <float> data;
        vector <Edge> edges = graph.tree_prima();
        for (Edge edge : edges) {
            data.push_back(edge.data);
        };
        sort(data.begin(), data.end());
        vector<float> res_data = { 1, 2, 3, 6, 7 };
        assert(res_data == data);
    };

    void test_7() {
        Graph graph;
        vector<vector<int>> list_adjacency = { {2, 5},{3, 5},{0, 4},{1, 4, 5},{3, 2}, {0, 1, 3} };
        vector<float> list_data = { 5, 2, 3, 7, 5, 1, 3, 7, 6, 7, 1, 2, 7, 6 };
        graph.set_adjacency_list(list_adjacency, list_data);
        vector <float> data;
        vector <Edge> edges = graph.tree_prima();
        for (Edge edge : edges) {
            data.push_back(edge.data);
        };
        sort(data.begin(), data.end());
        vector<float> res_data = { 1, 2, 3, 5, 6 };
        assert(res_data == data);
    };

    void test_8() {
        Graph graph;
        vector<vector<int>> list_adjacency = { {2, 5},{3, 5},{0, 4, 6},{1, 4, 5},{3, 2}, {0, 1, 3}, {3} };
        vector<float> list_data = { 5, 2, 3, 7, 5, 1, 11, 3, 7, 6, 7, 1, 2, 7, 6, 11 };
        graph.set_adjacency_list(list_adjacency, list_data);
        vector <float> data;
        vector <Edge> edges = graph.tree_prima();
        for (Edge edge : edges) {
            data.push_back(edge.data);
        };
        sort(data.begin(), data.end());
        vector<float> res_data = { 1, 2, 3, 5, 6, 11 };
        assert(res_data == data);
    };

    void test_9() {
        Graph graph;
        vector<vector<int>> list_adjacency = { {2, 5},{3, 5, 7},{0, 4},{1, 4, 5, 6, 7},{2, 3}, {0, 1, 3}, {3, 7}, {1, 3, 6} };
        vector<float> list_data = { 5, 2, 3, 7, 4, 5, 1, 3, 7, 6, 11, 4, 1, 7, 2, 7, 6, 11, 4, 4, 4, 4 };
        graph.set_adjacency_list(list_adjacency, list_data);
        vector <float> data;
        vector <Edge> edges = graph.tree_prima();
        for (Edge edge : edges) {
            data.push_back(edge.data);
        };
        sort(data.begin(), data.end());
        vector<float> res_data = { 1, 2, 3, 4, 4, 5, 6 };
        assert(res_data == data);
    };

    void test_10() {
        Graph graph;
        vector<vector<int>> list_adjacency = { {1, 2, 3},{0, 3},{0, 3},{0, 1, 2} };
        vector<float> list_data = { 4, 5, 1, 4, 1, 5, 11, 1, 1, 11 };
        graph.set_adjacency_list(list_adjacency, list_data);
        vector <float> data;
        vector <Edge> edges = graph.tree_prima();
        for (Edge edge : edges) {
            data.push_back(edge.data);
        };
        sort(data.begin(), data.end());
        vector<float> res_data = { 1, 1, 5 };
        assert(res_data == data);
    };
};

class TestTreeKraskal {
public:
    void test_1() {
        Graph graph;
        vector<vector<int>> list_adjacency = { {1, 2},{0, 3},{0, 4, 5},{1, 4, 5},{2, 3}, {2, 3} };
        vector<float> list_data = { 1, 5, 1, 3, 5, 1, 1, 3, 7, 6, 1, 7, 1, 6 };
        graph.set_adjacency_list(list_adjacency, list_data);
        vector <float> data;
        vector <Edge> edges = graph.tree_kraskal();
        for (Edge edge : edges) {
            data.push_back(edge.data);
        };
        sort(data.begin(), data.end());
        vector<float> res_data = { 1, 1, 1, 3, 5 };
        assert(res_data == data);
    };
    void test_2() {
        Graph graph;
        vector<vector<int>> list_adjacency = { {1, 2, 6, 7},{0, 3, 6},{0, 4, 5, 7},{1, 4, 5},{2, 3}, {2, 3}, {0, 1, 7}, {0, 2, 6} };
        vector<float> list_data = { 1, 5, 1, 4, 1, 3, 7, 5, 1, 1, 2, 3, 7, 6, 1, 7, 1, 6, 1, 7, 3, 4, 2, 3 };
        graph.set_adjacency_list(list_adjacency, list_data);
        vector <float> data;
        vector <Edge> edges = graph.tree_kraskal();
        for (Edge edge : edges) {
            data.push_back(edge.data);
        };
        sort(data.begin(), data.end());
        vector<float> res_data = { 1, 1, 1, 1, 2, 3, 3 };
        assert(res_data == data);
    };

    void test_3() {
        Graph graph;
        vector<vector<int>> list_adjacency = { {2, 7},{3, 6},{0, 4, 5, 7},{1, 4, 5},{2, 3}, {2, 3}, {1, 7}, {0, 2, 6} };
        vector<float> list_data = { 5, 4, 3, 7, 5, 1, 1, 2, 3, 7, 6, 1, 7, 1, 6, 7, 3, 4, 2, 3 };
        graph.set_adjacency_list(list_adjacency, list_data);
        vector <float> data;
        vector <Edge> edges = graph.tree_kraskal();
        for (Edge edge : edges) {
            data.push_back(edge.data);
        };
        sort(data.begin(), data.end());
        vector<float> res_data = { 1, 1, 2, 3, 3, 4, 6 };
        assert(res_data == data);
    };

    void test_4() {
        Graph graph;
        vector<vector<int>> list_adjacency = { {2},{3, 6},{0, 4, 5, 7},{1, 4, 5},{2, 3},{2, 3}, {1, 7}, {2, 6} };
        vector<float> list_data = { 5, 3, 7, 5, 1, 1, 2, 3, 7, 6, 1, 7, 1, 6, 7, 3, 2, 3 };
        graph.set_adjacency_list(list_adjacency, list_data);
        vector <float> data;
        vector <Edge> edges = graph.tree_kraskal();
        for (Edge edge : edges) {
            data.push_back(edge.data);
        };
        sort(data.begin(), data.end());
        vector<float> res_data = { 1, 1, 2, 3, 3, 5, 6 };
        assert(res_data == data);
    };

    void test_5() {
        Graph graph;
        vector<vector<int>> list_adjacency = { {2, 5},{3, 5},{0, 4, 5},{1, 4, 5},{2, 3}, {0, 1, 2, 3} };
        vector<float> list_data = { 5, 2, 3, 7, 5, 1, 1, 3, 7, 6, 1, 7, 2, 7, 1, 6 };
        graph.set_adjacency_list(list_adjacency, list_data);
        vector <float> data;
        vector <Edge> edges = graph.tree_kraskal();
        for (Edge edge : edges) {
            data.push_back(edge.data);
        };
        sort(data.begin(), data.end());
        vector<float> res_data = { 1, 1, 2, 3, 6 };
        assert(res_data == data);
    };

    void test_6() {
        Graph graph;
        vector<vector<int>> list_adjacency = { {2, 5},{3, 5},{0, 5},{1, 4, 5},{3}, {0, 1, 2, 3} };
        vector<float> list_data = { 5, 2, 3, 7, 5, 1, 3, 7, 6, 7, 2, 7, 1, 6 };
        graph.set_adjacency_list(list_adjacency, list_data);
        vector <float> data;
        vector <Edge> edges = graph.tree_kraskal();
        for (Edge edge : edges) {
            data.push_back(edge.data);
        };
        sort(data.begin(), data.end());
        vector<float> res_data = { 1, 2, 3, 6, 7 };
        assert(res_data == data);
    };

    void test_7() {
        Graph graph;
        vector<vector<int>> list_adjacency = { {2, 5},{3, 5},{0, 4},{1, 4, 5},{3, 2}, {0, 1, 3} };
        vector<float> list_data = { 5, 2, 3, 7, 5, 1, 3, 7, 6, 7, 1, 2, 7, 6 };
        graph.set_adjacency_list(list_adjacency, list_data);
        vector <float> data;
        vector <Edge> edges = graph.tree_kraskal();
        for (Edge edge : edges) {
            data.push_back(edge.data);
        };
        sort(data.begin(), data.end());
        vector<float> res_data = { 1, 2, 3, 5, 6 };
        assert(res_data == data);
    };

    void test_8() {
        Graph graph;
        vector<vector<int>> list_adjacency = { {2, 5},{3, 5},{0, 4, 6},{1, 4, 5},{3, 2}, {0, 1, 3}, {3} };
        vector<float> list_data = { 5, 2, 3, 7, 5, 1, 11, 3, 7, 6, 7, 1, 2, 7, 6, 11 };
        graph.set_adjacency_list(list_adjacency, list_data);
        vector <float> data;
        vector <Edge> edges = graph.tree_kraskal();
        for (Edge edge : edges) {
            data.push_back(edge.data);
        };
        sort(data.begin(), data.end());
        vector<float> res_data = { 1, 2, 3, 5, 6, 11 };
        assert(res_data == data);
    };

    void test_9() {
        Graph graph;
        vector<vector<int>> list_adjacency = { {2, 5},{3, 5, 7},{0, 4},{1, 4, 5, 6, 7},{2, 3}, {0, 1, 3}, {3, 7}, {1, 3, 6} };
        vector<float> list_data = { 5, 2, 3, 7, 4, 5, 1, 3, 7, 6, 11, 4, 1, 7, 2, 7, 6, 11, 4, 4, 4, 4 };
        graph.set_adjacency_list(list_adjacency, list_data);
        vector <float> data;
        vector <Edge> edges = graph.tree_kraskal();
        for (Edge edge : edges) {
            data.push_back(edge.data);
        };
        sort(data.begin(), data.end());
        vector<float> res_data = { 1, 2, 3, 4, 4, 5, 6 };
        assert(res_data == data);
    };

    void test_10() {
        Graph graph;
        vector<vector<int>> list_adjacency = { {1, 2, 3},{0, 3},{0, 3},{0, 1, 2} };
        vector<float> list_data = { 4, 5, 1, 4, 1, 5, 11, 1, 1, 11 };
        graph.set_adjacency_list(list_adjacency, list_data);
        vector <float> data;
        vector <Edge> edges = graph.tree_kraskal();
        for (Edge edge : edges) {
            data.push_back(edge.data);
        };
        sort(data.begin(), data.end());
        vector<float> res_data = { 1, 1, 5 };
        assert(res_data == data);
    };
};

class TestRandomTest {
public:
    void test_tree_kraskal() {
        Graph graph;
        srand(time(0));
        int count_nodes = rand() % 10 + 5;
        vector<vector<int>> matrix = random_matrix(count_nodes);
        vector<vector <int>> adjacency_list = random_adjacency_list(matrix);
        vector<float> data_list = random_data_list(matrix);
        graph.set_adjacency_list(adjacency_list, data_list);
        vector<Edge> tree = graph.tree_kraskal();

        int cont_right = 0;
        set<int> node_visit;
        if (not(tree.empty())) {
            vector<vector<int>> list_adjacency_tree = make_list_adjacency_tree(tree);
            for (Edge edge : tree) {
                node_visit.insert(edge.from);
                node_visit.insert(edge.to);
            };
            if (node_visit.size() == adjacency_list.size()) cont_right += 1;

            if (this_tree_or_not(0, list_adjacency_tree)) cont_right += 1;

            assert(cont_right == 2);
        }
    };
    void test_tree_prima() {
        Graph graph;
        srand(time(0));
        int count_nodes = rand() % 10 + 5;
        vector<vector<int>> matrix = random_matrix(count_nodes);
        vector<vector <int>> adjacency_list = random_adjacency_list(matrix);
        vector<float> data_list = random_data_list(matrix);
        graph.set_adjacency_list(adjacency_list, data_list);
        vector<Edge> tree = graph.tree_prima();

        int cont_right = 0;
        set<int> node_visit;
        if (not(tree.empty())) {
            vector<vector<int>> list_adjacency_tree = make_list_adjacency_tree(tree);
            for (Edge edge : tree) {
                node_visit.insert(edge.from);
                node_visit.insert(edge.to);
            };
            if (node_visit.size() == adjacency_list.size()) cont_right += 1;

            if (this_tree_or_not(0, list_adjacency_tree)) cont_right += 1;

            assert(cont_right == 2);
        }
    };
};

int main() {

    TestSetAdjacencyList test_set_adjacency_list;
    test_set_adjacency_list.test_1();
    test_set_adjacency_list.test_2();
    test_set_adjacency_list.test_3();
    test_set_adjacency_list.test_4();
    test_set_adjacency_list.test_5();
    test_set_adjacency_list.test_6();
    test_set_adjacency_list.test_7();
    test_set_adjacency_list.test_8();
    test_set_adjacency_list.test_9();
    test_set_adjacency_list.test_10();

    TestCheckConnect test_check_connect;
    test_check_connect.test_1();
    test_check_connect.test_2();
    test_check_connect.test_3();
    test_check_connect.test_4();
    test_check_connect.test_5();

    TestReturnMinEdge test_return_min_edge;
    test_return_min_edge.test_1();
    test_return_min_edge.test_2();
    test_return_min_edge.test_3();
    test_return_min_edge.test_4();
    test_return_min_edge.test_5();
    test_return_min_edge.test_6();

    TestTreePrima test_prima;
    test_prima.test_1();
    test_prima.test_2();
    test_prima.test_3();
    test_prima.test_4();
    test_prima.test_5();
    test_prima.test_6();
    test_prima.test_7();
    test_prima.test_8();
    test_prima.test_9();
    test_prima.test_10();

    TestTreeKraskal test_tree_kraskal;
    test_tree_kraskal.test_1();
    test_tree_kraskal.test_2();
    test_tree_kraskal.test_3();
    test_tree_kraskal.test_4();
    test_tree_kraskal.test_5();
    test_tree_kraskal.test_6();
    test_tree_kraskal.test_7();
    test_tree_kraskal.test_8();
    test_tree_kraskal.test_9();
    test_tree_kraskal.test_10();


    TestRandomTest random_test;
    random_test.test_tree_prima();
    random_test.test_tree_kraskal();
    return 0;
}