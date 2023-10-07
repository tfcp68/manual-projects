#include <bits/stdc++.h>

using namespace std;

template<typename ValueType>
ValueType grig_and_frogs_back(ValueType n, ValueType k, ValueType frogs[]){
    if(n < 0 or k < 0){
        return -1;
    }
    ValueType a[n + 1];
    for (int i = 0; i <= n; i++){
        a[i] = 0;
    }
    a[0] = 1;
    for (int i = 0; i < n + 1; i++){
        ValueType min;
        if (k <= i){
            min = k;
        }
        if (k > i){
            min = i;
        }
        for (int j = 1; j < min + 1; j++){
            a[i] = a[i - j] + a[i];

        }
        for (size_t q = 0; q <= sizeof( frogs ) / sizeof( *frogs ); q++){
            if (frogs[q] == i){
                a[i] = 0;
            }
        }
    }
    return a[n];
}

template<typename ValueType>
ValueType grig_and_frogs_forward(ValueType n, ValueType k, ValueType frogs[]){
    if(n < 0 or k < 0){
        return -1;
    }

    ValueType a[n + k + 1];
    for (int i = 0; i <= n + k; i++){
        a[i] = 0;
    }
    a[0] = 1;
    for (int i = 0; i < n + 1; i++){
        for (size_t q = 0; q <= sizeof( frogs ) / sizeof( *frogs ); q++){
            if (frogs[q] == i){
                a[i] = 0;
            }
        }
        for (int j = 1; j < k + 1; j++){
            a[i + j] = a[i + j] + a[i];
        }
    }
    return a[n];
}


