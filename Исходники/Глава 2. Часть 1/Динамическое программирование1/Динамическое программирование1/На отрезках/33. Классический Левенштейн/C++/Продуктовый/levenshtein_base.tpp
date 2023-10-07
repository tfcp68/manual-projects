#include <bits/stdc++.h>
#include <cassert>

using namespace std;

template<typename ValueType>
ValueType levenshtein_base(const string& a, const string& b) {
    ValueType n = a.length();
    ValueType m = b.length();
    vector<vector<ValueType>> l(n + 1, vector<ValueType>(m + 1, 0));

    for (int i = 0; i <= n; ++i) {
        l[i][0] = i;
    }

    for (int j = 0; j <= m; ++j) {
        l[0][j] = j;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            l[i][j] = min(l[i - 1][j], l[i][j - 1]) + 1;
            if (a[i - 1] == b[j - 1]){
                l[i][j] = l[i - 1][j - 1];
            }
            else{
                l[i][j] = min(l[i][j], l[i - 1][j - 1] + 1);
            }
        }
    }

    return l[n][m];
}
