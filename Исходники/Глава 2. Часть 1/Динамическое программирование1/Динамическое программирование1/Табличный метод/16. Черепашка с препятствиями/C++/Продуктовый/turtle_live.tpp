#include <bits/stdc++.h>
#include <cassert>

using namespace std;


template<typename ValueType>
ValueType turtle_live_back(ValueType n, ValueType m, ValueType hunters[][2]){
    if (n <= 0 or m <= 0){
        return -1;
    }
    ValueType Matrix[m][n];
    for(int j = 0; j < m; ++j)
        for(int i = 0; i < n; ++i)
            Matrix[j][i] = 0;
    Matrix[0][0] = 1;
    for(int j = 0; j < m; j++){
        for(int i = 0; i < n; i++){
            if (i != 0){
                Matrix[j][i] += Matrix[j][i - 1];
            }
            if (j != 0){
                Matrix[j][i] += Matrix[j - 1][i];
            }
            for (size_t q = 0; q <= sizeof( hunters ) / sizeof( *hunters ); q++){
                ValueType x = hunters[q][0];
                ValueType y = hunters[q][1];
                if (i == x && j == y){
                    Matrix[j][i] = 0;
                }
            }
        }
    }
    return Matrix[m - 1][n - 1];
}

template<typename ValueType>
ValueType turtle_live_forward(ValueType n, ValueType m, ValueType hunters[][2]){
    if (n <= 0 or m <= 0){
        return -1;
    }
    ValueType Matrix[m][n];
    for(int j = 0; j < m; ++j)
        for(int i = 0; i < n; ++i)
            Matrix[j][i] = 0;
    Matrix[0][0] = 1;
    for(int j = 0; j < m; j++){
        for(int i = 0; i < n; i++){
            for (size_t q = 0; q <= sizeof( hunters ) / sizeof( *hunters ); q++){
                ValueType x = hunters[q][0];
                ValueType y = hunters[q][1];
                if (i == x && j == y){
                    Matrix[j][i] = 0;
                }
            }
            if (i + 1 < n){
                Matrix[j][i + 1] += Matrix[j][i];
            }
            if (j + 1 < m){
                Matrix[j + 1][i] += Matrix[j][i];
            }
        }
    }
    return Matrix[m - 1][n - 1];
}
