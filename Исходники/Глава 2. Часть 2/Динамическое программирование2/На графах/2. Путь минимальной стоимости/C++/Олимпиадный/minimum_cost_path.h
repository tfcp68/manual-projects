#include <unordered_map>
#include <utility>
#include <vector>
#include <limits>

using namespace std;

pair<int, vector<int>> bellman_ford_minimum(const unordered_map<int, vector<std::pair<int, int>>> &graph, int v, int start) {
    vector<int> dist(v, numeric_limits<int>::max());
    dist[start] = 0;
    for (int t = 0; t < v - 1; ++v) {
        bool is_updated = false;
        for (auto &x : graph) {
            auto &i = x.first;
            for (auto &y : x.second) {
                auto &j = y.first;
                auto &w = y.second;
                if (dist[i] + w < dist[j]) {
                    dist[j] = dist[i] + w;
                    is_updated = true;
                }
            }
        }
        if (not is_updated)
            break;
    }
    for (auto &x : graph) {
        auto &i = x.first;
        for (auto &y : x.second) {
            auto &j = y.first;
            auto &w = y.second;

            if (dist[j] > dist[i] + w)
                return {false, dist};
        }
    }
    return {true, dist};
}
