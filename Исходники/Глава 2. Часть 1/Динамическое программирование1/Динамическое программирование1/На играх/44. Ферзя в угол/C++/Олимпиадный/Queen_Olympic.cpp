#include <vector>
#include <iostream>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;


void fill_table(vvi& dp, int n, int m) {
    for (int i = 0; i < m; i++) {
        dp[i][n - 1] = 1;
    }

    for (int j = 0; j < n; j++) {
        dp[m - 1][j] = 1;
    }

    int j = n - 1;
    for (int i = m - 1; i > -1; i--) {
        if (j >= 0) {
            dp[i][j] = 1;
            j -= 1;
        }
    }

    dp[m - 1][n - 1] = 0;
}


int winning_strategy(int m, int n, int x, int y) {
    vvi dp(m, vi(n, 0));

    fill_table(dp, n, m);

    for (int i = m - 2; i > -1; i--) {
        for (int j = n - 2; j > -1; j--) {
            if (dp[i][j + 1] and dp[i + 1][j] and dp[i + 1][j + 1]) {
                if (not dp[i][j]) {
                    fill_table(dp, j + 1, i + 1);
                }
            }
        }
    }
    return dp[x][y];
}
