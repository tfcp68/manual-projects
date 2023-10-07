#include <bits/stdc++.h>
#include <cassert>

using namespace std;

int turtle_point_forward(int n, int m, std::vector<std::vector<int>>& coins) {
    if (n <= 0 || m <= 0) {
        return -1;
    }
    std::vector<std::vector<int>> M(m, std::vector<int>(n, 0));
    M[0][0] = coins[0][0];
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if (i + 1 < n) {
                M[j][i + 1] = std::max(M[j][i] + coins[j][i + 1], M[j][i + 1]);
            }
            if (j + 1 < m) {
                M[j + 1][i] = std::max(M[j][i] + coins[j + 1][i], M[j + 1][i]);
            }
        }
    }
    return M[m - 1][n - 1];
}


int turtle_point_back(int n, int m, std::vector<std::vector<int>>& coins) {
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
            if (i != 0) {
                M[j][i] = std::max(M[j][i - 1] + coins[j][i], M[j][i]);
            }
            if (j != 0) {
                M[j][i] = std::max(M[j - 1][i] + coins[j][i], M[j][i]);
            }
        }
    }
    return M[m - 1][n - 1];
}