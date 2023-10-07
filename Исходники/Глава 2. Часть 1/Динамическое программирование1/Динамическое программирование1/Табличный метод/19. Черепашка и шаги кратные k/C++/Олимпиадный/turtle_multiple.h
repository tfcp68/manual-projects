#include <bits/stdc++.h>
#include <cassert>

using namespace std;


int turtle_multiple_forward(int n, int m, std::vector<std::vector<int>>& coins, int k) {
    if (k <= 0){
        return -1;
    }
    if (n <= 0 || m <= 0) {
        return -1;
    }
    std::vector<std::vector<int>> M(m, std::vector<int>(n, 0));
    M[0][0] = coins[0][0];

    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            for (int z = 1; z <= (n - i) / k; z++) {
                if (i + z * k < n) {
                    M[j][i + z * k] = std::max(M[j][i] + coins[j][i + z * k], M[j][i + z * k]);
                }
            }
            for (int z = 1; z <= (m - j) / k; z++) {
                if (j + z * k < m) {
                    M[j + z * k][i] = std::max(M[j][i] + coins[j + z * k][i], M[j + z * k][i]);
                }
            }
        }
    }

    return M[m - 1][n - 1];
}


int turtle_multiple_back(int n, int m, std::vector<std::vector<int>>& coins, int k) {
    if (k <= 0){
        return -1;
    }
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
            for (int z = 1; z <= i / k; z++) {
                if (i != 0) {
                    M[j][i] = std::max(M[j][i - z * k] + coins[j][i], M[j][i]);
                }
            }
            for (int z = 1; z <= j / k; z++) {
                if (j != 0) {
                    M[j][i] = std::max(M[j - z * k][i] + coins[j][i], M[j][i]);
                }
            }
        }
    }

    return M[m - 1][n - 1];
}
