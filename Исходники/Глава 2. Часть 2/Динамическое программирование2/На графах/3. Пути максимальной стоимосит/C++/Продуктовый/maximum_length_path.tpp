#include <unordered_map>
#include <utility>
#include <vector>
#include <limits>

template<typename ValueType>
std::pair<bool, std::vector<ValueType>> maximum_length_path(
        const std::unordered_map<ValueType, std::vector<std::pair<ValueType, ValueType>>> &graph,
        ValueType v, ValueType start) {
    std::vector<ValueType> distances(v, std::numeric_limits<ValueType>::min());
    distances[start] = 0;

    for (int t = 0; t < v - 1; ++v) {
        bool is_updated = false;

        for (auto &x : graph) {
            auto &i = x.first;
            for (auto &y : x.second) {
                auto &j = y.first;
                auto &w = y.second;
                if (distances[i] + 1 > distances[j]) {
                    distances[j] = distances[i] + 1;
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

            if (distances[j] < distances[i] + 1)
                return {false, distances};
        }
    }

    return {true, distances};
}
