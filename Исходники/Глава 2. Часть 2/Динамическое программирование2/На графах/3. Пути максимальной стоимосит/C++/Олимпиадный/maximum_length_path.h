#include <unordered_map>
#include <utility>
#include <vector>
#include <limits>

using namespace std;

pair<int, vector<int>>maximum_length_path(const unordered_map<int, vector<std::pair<int, int>>> &graph, int v, int start) {
    vector<int> dist(v, numeric_limits<int>::min());
    dist[start] = 0;
    for (int t = 0; t < v - 1; ++v) {
        bool is_updated = false;
        for (auto &x : graph) {
            auto &i = x.first;
            for (auto &y : x.second) {
                auto &j = y.first;
                if (dist[i] + 1 > dist[j]) {
                    dist[j] = dist[i] + 1;
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

            if (dist[j] < dist[i] + 1)
                return {false, dist};
        }
    }
    return {true, dist};
}
