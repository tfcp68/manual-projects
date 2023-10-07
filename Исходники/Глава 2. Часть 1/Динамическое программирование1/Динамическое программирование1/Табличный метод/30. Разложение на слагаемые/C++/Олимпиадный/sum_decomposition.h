#include <bits/stdc++.h>
#include <cassert>

using namespace std;


int sum_decomp(long n){
    if (n <= 0){
        return -1;
    }
    long sums[n + 1];
    for (int i = 0; i <= n; i++){
        sums[i] = 0;
    }
    sums[0] = 1;
    for (int i = 1; i <= n; i++){
        for (int j = i; j <= n; j++){
            sums[j] += sums[j - i];
        }
    }
    return sums[n] - 1;
}

