#include <bits/stdc++.h>
#include <cassert>

using namespace std;

template<typename ValueType>
ValueType turtle_random_forward(ValueType n, ValueType m, std::vector<std::vector<ValueType>>& coins, std::vector<ValueType>& steps) {
    if (n <= 0 || m <= 0) {
        return -1;
    }
    std::vector<std::vector<ValueType>> Matrix(m, std::vector<ValueType>(n, 0));
    Matrix[0][0] = coins[0][0];

    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            for (auto z: steps) {
                if (z > n - i - 1 || z == 0) {
                    continue;
                }
                Matrix[j][i + z] = std::max(Matrix[j][i] + coins[j][i + z], Matrix[j][i + z]);
            }
            for (auto z: steps) {
                if (z > m - j - 1 || z == 0) {
                    continue;
                }
                Matrix[j + z][i] = std::max(Matrix[j][i] + coins[j + z][i], Matrix[j + z][i]);
            }
        }
    }

    return Matrix[m - 1][n - 1];
}

template<typename ValueType>
ValueType turtle_random_back(ValueType n, ValueType m, std::vector<std::vector<ValueType>>& coins,
                             std::vector<ValueType>& steps) {
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
            for (auto z: steps) {
                if (z > i || z == 0) {
                    continue;
                }
                Matrix[j][i] = std::max(Matrix[j][i - z] + coins[j][i], Matrix[j][i]);
            }
            for (auto z: steps) {
                if (z > j || z == 0) {
                    continue;
                }
                Matrix[j][i] = std::max(Matrix[j - z][i] + coins[j][i], Matrix[j][i]);
            }
        }
    }

    return Matrix[m - 1][n - 1];
}

