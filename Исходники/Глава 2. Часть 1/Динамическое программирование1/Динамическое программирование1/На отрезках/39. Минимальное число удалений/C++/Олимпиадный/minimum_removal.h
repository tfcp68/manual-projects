#include <bits/stdc++.h>
#include <cassert>

using namespace std;

int minimum_removal(vector<int>& a) {
    int n = a.size();
    int b[n][n], f[n][n];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j ++){
            b[i][j] = false;
            f[i][j] = 0;
            f[i][j] = 0;
        }
    }
    for (int i = 0; i < n - 1; i++){
        b[i][i + 1] = true;
    }
    for (int len_ = 2; len_ < n; len_++){
        for (int i = 0; i < n - len_; i ++){
            int j = i + len_;
            for (int k = i + 1; k < j; k++){
                if(b[i][k] && b[k][j] && ((a[k] < a[i] && a[k] < a[j]) || (a[k] > a[i] && a[k] > a[j]))){
                    b[i][j] = true;
                }
            }
        }
    }
    for (int len_ = 1; len_ < n; len_++){
        for (int i = 0; i < n - len_; i++){
            int j = i + len_;
            f[i][j] = n;
            if (a[i] > a[j]){
                continue;
            }
            if (b[i][j]){
                f[i][j] = j - i - 1;
            }
            for (int k = i + 1; k < j; k++){
                if (f[i][k] + f[k][j] < f[i][j]){
                    f[i][j] = f[i][k] + f[k][j];
                }
            }
        }
    }
    if (f[0][n - 1] >= n){
        return -1;
    }
    else{
        return f[0][n - 1];
    }
}

