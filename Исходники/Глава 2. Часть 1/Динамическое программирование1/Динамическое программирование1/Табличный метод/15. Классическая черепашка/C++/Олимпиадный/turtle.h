#include <bits/stdc++.h>
#include <cassert>

using namespace std;

int turtle_forward(int n, int m){
    if (n <= 0 or m <= 0){
        return -1;
    }
    int M[m][n];
    for(int j = 0; j < m; ++j)
        for(int i = 0; i < n; ++i)
            M[j][i] = 0;
    M[0][0] = 1;
    for(int j = 0; j < m; j++){
        for(int i = 0; i < n; i++){
            if (i + 1 < n){
                M[j][i + 1] += M[j][i];
            }
            if (j + 1 < m){
                M[j + 1][i] += M[j][i];
            }
        }
    }
    return M[m - 1][n - 1];
}

int turtle_back(int n, int m){
    if (n <= 0 or m <= 0){
        return -1;
    }
    int M[m][n];
    for(int j = 0; j < m; ++j)
        for(int i = 0; i < n; ++i)
            M[j][i] = 0;
    M[0][0] = 1;
    for(int j = 0; j < m; j++){
        for(int i = 0; i < n; i++){
            if (i == 0 && j == 0){
                continue;
            }
            if (i != 0){
                M[j][i] += M[j][i - 1];
            }
            if (j != 0){
                M[j][i] += M[j - 1][i];
            }
        }
    }
    return M[m - 1][n - 1];
}