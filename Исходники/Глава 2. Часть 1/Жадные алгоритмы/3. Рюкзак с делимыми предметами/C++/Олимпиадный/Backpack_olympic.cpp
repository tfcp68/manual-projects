#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<pair<int, int>> vii;
typedef pair<double, double> dd;

bool comp(dd p_w_1, dd p_w_2) {
    return p_w_1.first / p_w_1.second > p_w_2.first / p_w_2.second;
}

int backpack(int W, int K, vi c, vi w) {
    vii items;
    for (int item = 0; item < K; ++item) {
        items.push_back(make_pair(c[item], w[item]));
    }
    sort(items.begin(), items.end(), comp);

    int res = 0;
    for (int item = 0; item < K; ++item) {
        res += min(items[item].second, W) * items[item].first;
        W -= min(items[item].second, W);
    }
    return res;
}