#include <bits/stdc++.h>
#include <cassert>

using namespace std;

template<typename ValueType>
ValueType turtle_and_k_step_forward(ValueType n, ValueType m, std::vector<std::vector<ValueType>>& coins, ValueType k) {
    if (n <= 0 || m <= 0) {
        return -1;
    }
    std::vector<std::vector<ValueType>> Matrix(m, std::vector<ValueType>(n, 0));
    Matrix[0][0] = coins[0][0];
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            ValueType r = std::min(k, n - i - 1);
            for (int z = 1; z <= r; z++) {
                if (i + 1 < n) {
                    Matrix[j][i + z] = std::max(Matrix[j][i] + coins[j][i + z], Matrix[j][i + z]);
                }
            }
            r = std::min(k, m - j - 1);
            for (int z = 1; z <= r; z++) {
                if (j + 1 < m) {
                    Matrix[j + z][i] = std::max(Matrix[j][i] + coins[j + z][i], Matrix[j + z][i]);
                }
            }
        }
    }
    return Matrix[m - 1][n - 1];
}

template<typename ValueType>
ValueType turtle_and_k_step_back(ValueType n, ValueType m, std::vector<std::vector<ValueType>>& coins, ValueType k) {
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
            ValueType r = std::min(k, i);
            for (int z = 1; z <= r; z++) {
                if (i != 0) {
                    Matrix[j][i] = std::max(Matrix[j][i - z] + coins[j][i], Matrix[j][i]);
                }
            }
            r = std::min(k, j);
            for (int z = 1; z <= r; z++) {
                if (j != 0) {
                    Matrix[j][i] = std::max(Matrix[j - z][i] + coins[j][i], Matrix[j][i]);
                }
            }
        }
    }
    return Matrix[m - 1][n - 1];
}
