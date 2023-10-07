#include <bits/stdc++.h>
#include <cassert>

using namespace std;

template<typename ValueType>
ValueType sum_decomp(ValueType n){
    ValueType sums[n + 1];
    for (int i = 0; i <= n; i++){
        sums[i] = 0;
    }
    sums[0] = 1;
    for (int i = 1; i < n; i++){
        for (int j = i; j <= n; j++){
            sums[j] += sums[j - i];
        }
    }
    return sums[n];
}