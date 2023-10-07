#include <bits/stdc++.h>
#include <cassert>

using namespace std;

template<typename ValueType>
ValueType minimum_removal(std::vector<ValueType>& a) {
    ValueType n = a.size();
    ValueType bool_[n][n], min_remove[n][n];

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j ++){
            bool_[i][j] = false;
            min_remove[i][j] = 0;
        }
    }

    for (int i = 0; i < n - 1; i++){
        bool_[i][i + 1] = true;
    }

    for (int len_ = 2; len_ < n; len_++){
        for (int i = 0; i < n - len_; i ++){
            int j = i + len_;
            for (int k = i + 1; k < j; k++){
                if(bool_[i][k] && bool_[k][j] && ((a[k] < a[i] && a[k] < a[j]) || (a[k] > a[i] && a[k] > a[j]))){
                    bool_[i][j] = true;
                }
            }
        }
    }

    for (int len_ = 1; len_ < n; len_++){
        for (int i = 0; i < n - len_; i++){
            int j = i + len_;
            min_remove[i][j] = n;
            if (a[i] > a[j]){
                continue;
            }
            if (bool_[i][j]){
                min_remove[i][j] = j - i - 1;
            }
            for (int k = i + 1; k < j; k++){
                if (min_remove[i][k] + min_remove[k][j] < min_remove[i][j]){
                    min_remove[i][j] = min_remove[i][k] + min_remove[k][j];
                }
            }
        }
    }

    if (min_remove[0][n - 1] >= n){
        return -1;
    }
    else{
        return min_remove[0][n - 1];
    }
}
