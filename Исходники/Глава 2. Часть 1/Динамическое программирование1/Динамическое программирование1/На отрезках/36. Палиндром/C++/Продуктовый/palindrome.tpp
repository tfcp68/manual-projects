#include <bits/stdc++.h>
#include <cassert>

using namespace std;

template<typename ValueType>
ValueType palindrome(const std::string& str_) {
    int n = str_.length();
    int p[2][n];

    for (int i = 0; i < n; i++){
        p[0][i] = 0;
        p[1][i] = 0;
    }

    for (int i = n - 1; i >= 0; i--){
        for (int j = i + 1; j < n; j ++){
            if (str_[i] == str_[j]){
                p[1][j] = p[0][j - 1];
            }
            else{
                p[1][j] = 1 + std::min(p[0][j], p[1][j - 1]);
            }
        }
        for (int j = 0; j < n; j ++){
            p[0][j] = p[1][j];
            p[1][j] = 0;
        }
    }

    return p[0][n - 1];
}

template<typename ValueType>
ValueType palindrome_matrix(const std::string& str_) {
    int n = str_.length();
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
            else if (str_[i] == str_[j]){
                p[i][j] = p[i + 1][j - 1];
            }
            else{
                p[i][j] = std::min(p[i + 1][j], p[i][j - 1]) + 1;
            }
        }
    }

    return p[0][n - 1];
}
