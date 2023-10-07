#include <bits/stdc++.h>
#include <cassert>

using namespace std;

template<typename ValueType>
ValueType turtle_multiple_forward(ValueType n, ValueType m, std::vector<std::vector<ValueType>>& coins, ValueType k) {
    if (k <= 0){
        return -1;
    }
    if (n <= 0 || m <= 0) {
        return -1;
    }
    std::vector<std::vector<ValueType>> Matrix(m, std::vector<ValueType>(n, 0));
    Matrix[0][0] = coins[0][0];

    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            for (int z = 1; z <= (n - i) / k; z++) {
                if (i + z * k < n) {
                    Matrix[j][i + z * k] = std::max(Matrix[j][i] + coins[j][i + z * k], Matrix[j][i + z * k]);
                }
            }
            for (int z = 1; z <= (m - j) / k; z++) {
                if (j + z * k < m) {
                    Matrix[j + z * k][i] = std::max(Matrix[j][i] + coins[j + z * k][i], Matrix[j + z * k][i]);
                }
            }
        }
    }

    return Matrix[m - 1][n - 1];
}

template<typename ValueType>
ValueType turtle_multiple_back(ValueType n, ValueType m, std::vector<std::vector<ValueType>>& coins, ValueType k) {
    if (k <= 0){
        return -1;
    }
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
            for (int z = 1; z <= i / k; z++) {
                if (i != 0) {
                    Matrix[j][i] = std::max(Matrix[j][i - z * k] + coins[j][i], Matrix[j][i]);
                }
            }
            for (int z = 1; z <= j / k; z++) {
                if (j != 0) {
                    Matrix[j][i] = std::max(Matrix[j - z * k][i] + coins[j][i], Matrix[j][i]);
                }
            }
        }
    }

    return Matrix[m - 1][n - 1];
}
