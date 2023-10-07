#include <bits/stdc++.h>
#include <cassert>

using namespace std;

int turtle_and_k_step_forward(int n, int m, std::vector<std::vector<int>>& coins, int k) {
    if (n <= 0 || m <= 0) {
        return -1;
    }
    std::vector<std::vector<int>> M(m, std::vector<int>(n, 0));
    M[0][0] = coins[0][0];
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            int r = std::min(k, n - i - 1);
            for (int z = 1; z <= r; z++) {
                if (i + 1 < n) {
                    M[j][i + z] = std::max(M[j][i] + coins[j][i + z], M[j][i + z]);
                }
            }
            r = std::min(k, m - j - 1);
            for (int z = 1; z <= r; z++) {
                if (j + 1 < m) {
                    M[j + z][i] = std::max(M[j][i] + coins[j + z][i], M[j + z][i]);
                }
            }
        }
    }
    return M[m - 1][n - 1];
}


int turtle_and_k_step_back(int n, int m, std::vector<std::vector<int>>& coins, int k) {
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
            int r = std::min(k, i);
            for (int z = 1; z <= r; z++) {
                if (i != 0) {
                    M[j][i] = std::max(M[j][i - z] + coins[j][i], M[j][i]);
                }
            }
            r = std::min(k, j);
            for (int z = 1; z <= r; z++) {
                if (j != 0) {
                    M[j][i] = std::max(M[j - z][i] + coins[j][i], M[j][i]);
                }
            }
        }
    }
    return M[m - 1][n - 1];
}
