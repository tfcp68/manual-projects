#include <bits/stdc++.h>
#include <cassert>

using namespace std;

int deleting_sequence(vector<int>& a) {
    int n = a.size();
    if (n <= 2){
        return 0;
    }
    int f[n][n];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            f[i][j] = 0;
        }
    }
    for (int len_ = 2; len_ <= n; len_++){
        for (int i = 0; i < n - len_; i++){
            int j = i + len_;
            f[i][j] = numeric_limits<int>::max();
            for (int k = i + 1; k < j; k++){
                int v = f[i][k] + f[k][j] + a[k] * (a[i] + a[j]);
                f[i][j] = min(f[i][j], v);
            }
        }
    }
    return f[0][n - 1];
}