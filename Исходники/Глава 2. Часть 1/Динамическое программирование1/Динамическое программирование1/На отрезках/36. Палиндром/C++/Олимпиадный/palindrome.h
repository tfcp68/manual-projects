#include <bits/stdc++.h>
#include <cassert>

using namespace std;

int palindrome(const string& s) {
    int n = s.length();
    int p[2][n];
    for (int i = 0; i < n; i++){
        p[0][i] = 0;
        p[1][i] = 0;
    }
    for (int i = n - 1; i >= 0; i--){
        for (int j = i + 1; j < n; j ++){
            if (s[i] == s[j]){
                p[1][j] = p[0][j - 1];
            }
            else{
                p[1][j] = 1 + min(p[0][j], p[1][j - 1]);
            }
        }
        for (int j = 0; j < n; j ++){
            p[0][j] = p[1][j];
            p[1][j] = 0;
        }
    }
    return p[0][n - 1];
}


int palindrome_matrix(const string& s) {
    int n = s.length();
    if (n == 0){
        return 0;
    }
    int p[n][n];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            p[i][j] = 0;
        }
    }
    for (int i = n - 1; i >= 0; i--){
        for (int j = 0; j < n; j ++){
            if (i >= j){
                p[i][j] = 0;
            }
            else if (s[i] == s[j]){
                p[i][j] = p[i + 1][j - 1];
            }
            else{
                p[i][j] = min(p[i + 1][j], p[i][j - 1]) + 1;
            }
        }
    }
    return p[0][n - 1];
}