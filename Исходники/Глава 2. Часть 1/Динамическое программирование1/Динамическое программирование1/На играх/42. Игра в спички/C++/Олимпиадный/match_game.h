#include <bits/stdc++.h>
#include <cassert>

using namespace std;

vector<int> match_game(int n, int k) {
    vector<vector<bool>> bool_(n + 1, vector<bool>(n + 1, false));
    vector<int> answer;

    for (int j = 1; j <= n; ++j) {
        bool_[0][j] = true;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int m = j + 1;
            if (m >= i) {
                m = i - 1;
            }
            for (int t = 1; t <= m; ++t) {
                bool_[i][j] = bool_[i][j] || (!bool_[i - t][t]);
            }
        }
    }

    int m = k;
    if (m > n) {
        m = n;
    }

    for (int t = 1; t <= m; ++t) {
        if (!bool_[n - t][t]) {
            answer.push_back(t);
        }
    }

    return answer;
}
