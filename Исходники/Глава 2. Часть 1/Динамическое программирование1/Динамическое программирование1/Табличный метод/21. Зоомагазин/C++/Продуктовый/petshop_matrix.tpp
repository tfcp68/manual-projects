#include <bits/stdc++.h>

using namespace std;

template<typename ValueType>
ValueType petshop_matrix(ValueType n){
    if(n < 0){
        return -1;
    }
    ValueType matrix[n][n];
    ValueType sum_3 = 0;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            if (j == 0 && i == 0){
                matrix[i][j] = 1;
            }
            else if (i == 0){
                matrix[i][j] = pow(2, j - 1);
            }
            else{
                matrix[i][j] = matrix[i - 1][j - 1];
            }
            if (j >= 2 && i >= 2){
                sum_3 += matrix[i][j];
            }
        }
    }
    ValueType answer = pow(2, n) - sum_3;
    if (n==0){
        answer = 0;
    }
    return answer;
}