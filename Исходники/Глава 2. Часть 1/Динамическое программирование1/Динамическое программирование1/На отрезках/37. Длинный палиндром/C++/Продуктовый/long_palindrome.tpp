#include <bits/stdc++.h>
#include <cassert>

using namespace std;

template<typename ValueType>
ValueType long_palindrome(const string& line) {
    ValueType n = line.length();
    ValueType p[n][n];

    for (int i = 0; i < n; i++){
        p[i][i] = 1;
    }

    for (int len_ = 1; len_ < n; len_++){
        for (int i = 0; i < n - len_; i++){
            int j = i + len_;
            if (line[i] == line[j]){
                p[i][j] = p[i + 1][j - 1] + 2;
            }
            else{
                p[i][j] = std::max(p[i + 1][j], p[i][j - 1]);
            }
        }
    }
    return p[0][n - 1];
}

