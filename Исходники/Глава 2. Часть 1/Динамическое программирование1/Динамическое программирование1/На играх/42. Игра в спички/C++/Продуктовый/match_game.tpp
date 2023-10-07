#include <bits/stdc++.h>
#include <cassert>

using namespace std;

template<typename ValueType>
std::vector<ValueType> match_game(ValueType n, ValueType k) {
    std::vector<std::vector<bool>> bool_(n + 1, std::vector<bool>(n + 1, false));
    std::vector<ValueType> answer;

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

    ValueType m = k;
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
