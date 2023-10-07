#include <bits/stdc++.h>
#include <cassert>

using namespace std;

template<typename ValueType>
ValueType turtle_point_back(ValueType n, ValueType m, std::vector<std::vector<ValueType>>& coins) {
    if (n <= 0 || m <= 0) {
        return -1;
    }
    std::vector<std::vector<ValueType>> Matrix(m, std::vector<ValueType>(n, 0));
    Matrix[0][0] = coins[0][0];
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if (i == 0 && j == 0) {
                continue;
            }
            if (i != 0) {
                Matrix[j][i] = std::max(Matrix[j][i - 1] + coins[j][i], Matrix[j][i]);
            }
            if (j != 0) {
                Matrix[j][i] = std::max(Matrix[j - 1][i] + coins[j][i], Matrix[j][i]);
            }
        }
    }
    return Matrix[m - 1][n - 1];
}

template<typename ValueType>
ValueType turtle_point_forward(ValueType n, ValueType m, std::vector<std::vector<ValueType>>& coins) {
    if (n <= 0 || m <= 0) {
        return -1;
    }
    std::vector<std::vector<ValueType>> Matrix(m, std::vector<ValueType>(n, 0));
    Matrix[0][0] = coins[0][0];
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if (i + 1 < n) {
                Matrix[j][i + 1] = std::max(Matrix[j][i] + coins[j][i + 1], Matrix[j][i + 1]);
            }
            if (j + 1 < m) {
                Matrix[j + 1][i] = std::max(Matrix[j][i] + coins[j + 1][i], Matrix[j + 1][i]);
            }
        }
    }
    return Matrix[m - 1][n - 1];
}
