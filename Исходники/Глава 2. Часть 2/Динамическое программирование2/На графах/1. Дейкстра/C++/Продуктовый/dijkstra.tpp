#include <limits>
#include <vector>
#include <queue>


template<typename ValueType>
std::vector<ValueType> dijkstra(const std::vector<std::vector<ValueType>> &graph, ValueType start) {
    const int MAX_INT = std::numeric_limits<ValueType>::max();
    int v = graph.size();
    std::vector<ValueType> dist(v, MAX_INT);
    std::vector<bool> visited(v, false);
    dist[start] = 0;

    for (int i = 0; i < v; ++i) {
        ValueType min_dist = MAX_INT;
        int min_index = -1;

        for (int j = 0; j < v; ++j) {
            if (!visited[j] && dist[j] < min_dist) {
                min_dist = dist[j];
                min_index = j;
            }
        }

        if (min_index == -1) {
            break;
        }

        visited[min_index] = true;
        for (int j = 0; j < v; ++j) {
            if (!visited[j] && graph[min_index][j] != MAX_INT) {
                dist[j] = std::min(dist[j], dist[min_index] + graph[min_index][j]);
            }
        }
    }

    return dist;
}

template<typename ValueType>
std::vector<int> heap_dijkstra(const std::vector<std::vector<int>> &graph, int start) {
    const int MAX_INT = std::numeric_limits<int>::max();
    int n = graph.size();
    std::vector<int> dist(n, MAX_INT);
    std::vector<bool> visited(n, false);
    dist[start] = 0;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    pq.push(std::make_pair(0, start));
    while (!pq.empty()) {
        int min_dist = pq.top().first;
        int min_idx = pq.top().second;
        pq.pop();
        if (visited[min_idx]) {
            continue;
        }
        visited[min_idx] = true;
        for (int j = 0; j < n; ++j) {
            if (!visited[j] && graph[min_idx][j] != MAX_INT) {
                dist[j] = std::min(dist[j], dist[min_idx] + graph[min_idx][j]);
                pq.push(std::make_pair(dist[j], j));
            }
        }
    }
    return dist;
}
