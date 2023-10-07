#include <bits/stdc++.h>
#include <cassert>

using namespace std;

int turtle_random_forward(int n, int m, std::vector<std::vector<int>>& coins, std::vector<int>& steps) {
    if (n <= 0 || m <= 0) {
        return -1;
    }
    std::vector<std::vector<int>> M(m, std::vector<int>(n, 0));
    M[0][0] = coins[0][0];

    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            for (auto z: steps) {
                if (z > n - i - 1 || z == 0) {
                    continue;
                }
                M[j][i + z] = std::max(M[j][i] + coins[j][i + z], M[j][i + z]);
            }
            for (auto z: steps) {
                if (z > m - j - 1 || z == 0) {
                    continue;
                }
                M[j + z][i] = std::max(M[j][i] + coins[j + z][i], M[j + z][i]);
            }
        }
    }

    return M[m - 1][n - 1];
}


int turtle_random_back(int n, int m, std::vector<std::vector<int>>& coins, std::vector<int>& steps) {
    if (n <= 0 || m <= 0) {
        return -1;
    }

    std::vector<std::vector<int>> M(m, std::vector<int>(n, 0));
    M[0][0] = coins[0][0];

    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if (i == 0 && j == 0) {
                continue;
            }
            for (auto z: steps) {
                if (z > i || z == 0) {
                    continue;
                }
                M[j][i] = std::max(M[j][i - z] + coins[j][i], M[j][i]);
            }
            for (auto z: steps) {
                if (z > j || z == 0) {
                    continue;
                }
                M[j][i] = std::max(M[j - z][i] + coins[j][i], M[j][i]);
            }
        }
    }

    return M[m - 1][n - 1];
}
