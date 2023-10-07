#include <limits>
#include <vector>
#include <queue>

using namespace std;

vector<int> minimum_length_path(const vector<vector<int>> &g, int s) {
    const int MAX_INT = numeric_limits<int>::max();
    int n = g.size();
    vector<int> dist(n, MAX_INT);
    vector<bool> visited(n, false);
    dist[s] = 0;
    for (int i = 0; i < n; ++i) {
        int min_dist = MAX_INT;
        int min_i = -1;
        for (int j = 0; j < n; ++j) {
            if (!visited[j] && dist[j] < min_dist) {
                min_dist = dist[j];
                min_i = j;
            }
        }
        visited[min_i] = true;
        for (int j = 0; j < n; ++j) {
            if (!visited[j] && g[min_i][j] != MAX_INT) {
                dist[j] = min(dist[j], dist[min_i] + 1);
            }
        }
    }
    return dist;
}

vector<int> heap_minimum_length_path(const vector<vector<int>> &graph, int start) {
    const int MAX_INT = numeric_limits<int>::max();
    int n = graph.size();
    vector<int> dist(n, MAX_INT);
    vector<bool> visited(n, false);
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, start));
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
                dist[j] = min(dist[j], dist[min_idx] + 1);
                pq.push(make_pair(dist[j], j));
            }
        }
    }
    return dist;
}
