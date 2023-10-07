#include <bits/stdc++.h>
#include <cassert>

using namespace std;


template<typename ValueType>
ValueType opt_damage_forward_random(ValueType n, ValueType steps[ ], ValueType frogs[], ValueType damage[]){
    ValueType arr[n + 1];
    for (int i = 0; i < n + 1; i++){
        arr[i] = std::numeric_limits<int>::max();
    }
    arr[0] = 0;
    for (size_t q = 0; q <= sizeof( frogs ) / sizeof( *frogs ); q++){
        if (frogs[q] == n){
            return -1;
        }
    }
    for (int i = 0; i < n; i++){
        for (size_t q = 0; q < sizeof( frogs ) / sizeof( *frogs ); q++){
            if (frogs[q] == i){
                arr[i] = std::numeric_limits<ValueType>::max();
            }
        }
        for (size_t j = 0; j < sizeof( steps ) / sizeof( *steps ); j++){
            if (steps[j] <= n - i){
                ValueType count;
                count = arr[i] + damage[i + steps[j] - 1];
                if (count < arr[i + steps[j]] && count > 0){
                    arr[i + steps[j]] = count;
                }
            }
        }
    }
    if (arr[n] == std::numeric_limits<ValueType>::max()){
        return -1;
    }
    return arr[n];
}

template<typename ValueType>
ValueType opt_damage_back_random(ValueType n, ValueType steps[], ValueType frogs[], ValueType damage[]){
    ValueType arr[n + 1];
    for (int i = 0; i < n + 1; i++){
        arr[i] = std::numeric_limits<int>::max();
    }
    arr[0] = 0;
    for (size_t q = 0; q < sizeof( frogs ) / sizeof( *frogs ); q++){
        if (frogs[q] == n){
            return -1;
        }
    }
    for (int i = 0; i <= n; i++){
        for (size_t j = 0; j < sizeof( steps ) / sizeof( *steps ); j++){
            if (steps[j] <= i){
                for (size_t q = 0; q < sizeof( frogs ) / sizeof( *frogs ); q++){
                    if (frogs[q] == i - steps[j]){
                        arr[i - steps[j]] = std::numeric_limits< ValueType>::max();
                    }
                }
                ValueType count;
                count = arr[i - steps[j]] + damage[i - 1];
                if (count < arr[i] && count > 0){
                    arr[i] = count;
                }
            }
        }
    }
    if (arr[n] == std::numeric_limits<ValueType>::max()){
        return -1;
    }
    return arr[n];
}
