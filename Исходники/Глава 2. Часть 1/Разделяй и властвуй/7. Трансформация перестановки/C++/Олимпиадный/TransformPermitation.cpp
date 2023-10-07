#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>

std::map<int, std::vector<int>> build_tree(std::vector<int> array, std::map<int, std::vector<int>>& tree) {
    int root = *std::max_element(array.begin(), array.end());
    std::vector<int>::iterator itr = std::find(array.begin(), array.end(), root);
    int index_root = std::distance(array.begin(), itr);
    array.erase(array.begin() + index_root);

    std::vector<int> left;
    std::vector<int> right;

    left.insert(left.end(), array.begin(), array.begin() + index_root);
    right.insert(right.end(), array.begin() + index_root, array.end());

    if (left.size() > 0) {
        int new_root = *std::max_element(left.begin(), left.end());
        tree[root].push_back(new_root);
        build_tree(left, tree);
    }

    if (right.size() > 0) {
        int new_root = *std::max_element(right.begin(), right.end());
        tree[root].push_back(new_root);
        build_tree(right, tree);
    }
    return tree;
}


std::vector<int> bfs(std::map<int, std::vector<int>> graph, int start) {
    std::vector<int> deeps(graph.size() + 1, graph.size());
    deeps[start] = 0;
    std::queue<int> queue;
    queue.push(start);

    while (queue.empty() != 1) {
        int node = queue.front();
        queue.pop();

        for (int i : graph[node]) {
            if (deeps[i] > deeps[node] + 1) {
                deeps[i] = deeps[node] + 1;
                queue.push(i);
            }
        }
    }
    return deeps;
}


void solver() {
    int len_permutation;
    std::cin >> len_permutation;

    std::vector<int> permutation;
    for (int i = 0; i < len_permutation; i++) {
        int digit;
        std::cin >> digit;
        permutation.push_back(digit);
    }

    int start = *std::max_element(permutation.begin(), permutation.end());

    std::map<int, std::vector<int>> tree;
    for (int i : permutation) {
        std::vector<int> v;
        tree[i] = v;
    }

    build_tree(permutation, tree);

    std::vector<int> deeps = bfs(tree, start);

    for (int i : permutation) {
        std::cout << deeps[i] << " ";
    }
    std::cout << std::endl;
}



