#include <bits/stdc++.h>

using namespace std;

template<typename ValueType>
ValueType optimal_damage_forward(ValueType n, ValueType k, ValueType frogs[], ValueType damage[]) {
    ValueType arr[n + 1];
    for (int i = 0; i < n + 1; i++) {
        arr[i] = std::numeric_limits<ValueType>::max();
    }
    arr[0] = 0;
    for (size_t q = 0; q <= sizeof(frogs) / sizeof(*frogs); q++) {
        if (frogs[q] == n) {
            return -1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (size_t q = 0; q <= sizeof(frogs) / sizeof(*frogs); q++) {
            if (frogs[q] == i) {
                arr[i] = std::numeric_limits<ValueType>::max();
            }
        }
        int r;
        if (k <= (n - i)) {
            r = k;
        }
        if (k > (n - i)) {
            r = n - i;
        }
        for (int j = 1; j < r + 1; j++) {
            ValueType count;
            count = arr[i] + damage[i + j - 1];
            if (count < arr[i + j] && count > 0) {
                arr[i + j] = count;
            }
        }
    }
    if (arr[n] == std::numeric_limits<ValueType>::max()) {
        return -1;
    }
    return arr[n];
}

template<typename ValueType>
ValueType optimal_damage_back(ValueType n, ValueType k, ValueType frogs[], ValueType damage[]){
    ValueType arr[n + 1];
    for (int i = 0; i < n + 1; i++){
        arr[i] = std::numeric_limits<ValueType>::max();
    }
    arr[0] = 0;
    for (size_t q = 0; q <= sizeof( frogs ) / sizeof( *frogs ); q++){
        if (frogs[q] == n){
            return -1;
        }
    }
    for (int i = 1; i < n + 1; i++){
        int r;
        if (k <= i){
            r = k;
        }
        if (k > i){
            r = i;
        }
        for (int j = 1; j < r + 1; j++){
            for (size_t q = 0; q <= sizeof( frogs ) / sizeof( *frogs ); q++){
                if (frogs[q] == i - j){
                    arr[i - j] = std::numeric_limits<ValueType>::max();
                }
            }
            ValueType count;
            count = arr[i - j] + damage[i - 1];
            if (count < arr[i] && count > 0){
                arr[i] = count;
            }
        }
    }
    if (arr[n] == std::numeric_limits<ValueType>::max()){
        return -1;
    }
    return arr[n];
}


template<typename ValueType>
ValueType output_way(ValueType *W, ValueType *damage, ValueType n, ValueType k){
    if (n == 0){
        cout << 0;
    }
    ValueType r;
    if (k > n){
        r = n;
    }
    if (k <= n){
        r = k;
    }
    for (int i = 1; i < r+1; i++){
        if (W[n] == W[n - i] + damage[n - 1]){
            if (n != 0){
                output_way(W, damage, n - i, k);
                cout << " " << n;
            }
        }
    }
}