#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare_pair(pair<int, int> p_w_1, pair<int, int> p_w_2) {
    return p_w_1.first / p_w_1.second > p_w_2.first / p_w_2.second;
}

int backpack(int capacity, int count_items,
    vector<int> price_items, vector<int> weight_items) {
    vector<pair<int, int>> items;
    for (int item = 0; item < count_items; ++item) {
        items.push_back(make_pair(price_items[item],
                                  weight_items[item]));
    }
    sort(items.begin(), items.end(), compare_pair);
    int amount = 0;
    for (int item = 0; item < count_items; ++item) {
        int current_weight = min(items[item].second, capacity);
        amount += current_weight * items[item].first;
        capacity -= current_weight;
    }
    return amount;
}