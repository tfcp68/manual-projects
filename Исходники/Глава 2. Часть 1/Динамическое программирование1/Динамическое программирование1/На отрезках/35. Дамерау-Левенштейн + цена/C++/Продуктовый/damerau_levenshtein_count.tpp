#include <bits/stdc++.h>
#include <cassert>

using namespace std;

template<typename ValueType>
ValueType damerau_levenshtein_count(const string& a, const string& b) {
    vector<char> alpha;
    for (int i = 97; i <= 122; ++i) {
        alpha.push_back(static_cast<char>(i));
    }

    ValueType n = a.length();
    ValueType m = b.length();
    vector<vector<ValueType>> l(n + 1, std::vector<ValueType>(m + 1, 0));

    for (int i = 1; i <= n; ++i) {
        l[i][0] = l[i - 1][0] + find(alpha.begin(), alpha.end(), a[i - 1]) - alpha.begin() + 1;
    }

    for (int j = 1; j <= m; ++j) {
        l[0][j] = l[0][j - 1] + find(alpha.begin(), alpha.end(), b[j - 1]) - alpha.begin() + 1;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int ind_i = find(alpha.begin(), alpha.end(), a[i - 1]) - alpha.begin() + 1;
            int ind_j = find(alpha.begin(), alpha.end(), b[j - 1]) - alpha.begin() + 1;
            l[i][j] = std::min(l[i - 1][j] + ind_i, l[i][j - 1] + ind_j);
            if (i > 1 && j > 1 && a[i - 1] == b[j - 2] && a[i - 2] == b[j - 1]) {
                int count = l[i - 1][j - 1];
                l[i][j] = min(l[i][j], count + 1);
            }
            if (a[i - 1] == b[j - 1]) {
                l[i][j] = l[i - 1][j - 1];
            }
            else {
                int count = l[i - 1][j - 1];
                if (i == 1 && j == 1) {
                    count = 0;
                }
                l[i][j] = min(l[i][j], count + abs(ind_j - ind_i));
            }
        }
    }

    return l[n][m];
}

