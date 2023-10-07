#include <bits/stdc++.h>

using namespace std;


int petshop_matrix(int n){
    if(n < 0){
        return -1;
    }
    int m[n][n];
    int sum_3 = 0;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            if (j == 0 && i == 0){
                m[i][j] = 1;
            }
            else if (i == 0){
                m[i][j] = pow(2, j - 1);
            }
            else{
                m[i][j] = m[i - 1][j - 1];
            }
            if (j >= 2 && i >= 2){
                sum_3 += m[i][j];
            }
        }
    }
    int ans = pow(2, n) - sum_3;
    if (n==0){
        ans = 0;
    }
    return ans;
}
