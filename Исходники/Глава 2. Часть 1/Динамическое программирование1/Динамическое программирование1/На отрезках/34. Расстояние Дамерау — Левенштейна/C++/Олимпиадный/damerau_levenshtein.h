#include <bits/stdc++.h>
#include <cassert>

using namespace std;

int damerau_levenshtein(const string& a, const string& b) {
    int n = a.length();
    int m = b.length();
    vector<vector<int>> l(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; ++i) {
        l[i][0] = i;
    }
    for (int j = 0; j <= m; ++j) {
        l[0][j] = j;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            l[i][j] = min(l[i - 1][j], l[i][j - 1]) + 1;
            if (a[i - 2] == b[j - 1] && a[i - 1] == b[j - 2]){
                l[i][j] = min(l[i][j], l[i - 2][j - 2] + 1);
            }
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
