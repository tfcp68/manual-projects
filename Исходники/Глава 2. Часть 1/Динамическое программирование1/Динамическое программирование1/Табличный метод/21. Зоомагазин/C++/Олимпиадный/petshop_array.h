#include <bits/stdc++.h>

using namespace std;

int petshop_array(int n){
    if(n < 0){
        return -1;
    }
    if(n == 0){
        return 0;
    }
    if(n < 3){
        return pow(2, n);
    }
    int a[n + 3];
    for(int i = 0; i <= n; i++){
        a[i] = 0;
    }
    for(int i = 3; i <= n; i++){
        a[i] = a[i - 1] + pow(2, i - 3);
    }
    int ans;
    ans = pow(2, n) - a[n];
    return ans;
}