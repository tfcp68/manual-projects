#include <bits/stdc++.h>
#include <cassert>

using namespace std;

template<typename ValueType>
ValueType grig_and_any_steps(ValueType number, int steps[ ]){
    int arr[number + 1];
    for (int i = 0; i <= number + 1; i++){
        arr[i] = 0;
    }
    arr[0] = 1;
    for (int i = 1; i < number + 1; i++){
        for (size_t j = 0; j <= sizeof( steps ) / sizeof( *steps ); j++){
            if (steps[j] <= i){
                arr[i] = arr[i] + arr[i - steps[j]];
            }
        }
    }
    return arr[number];
}

template<typename ValueType>
ValueType opt_damage_forward_random(ValueType number, int steps[ ], int frogs[], int danger[]){
    int a[number + 1];
    for (int i = 0; i < number + 1; i++){
        a[i] = std::numeric_limits<int>::max();
    }
    a[0] = 0;
    for (size_t q = 0; q <= sizeof( frogs ) / sizeof( *frogs ); q++){
        if (frogs[q] == number){
            return -1;
        }
    }
    for (int i = 0; i < number; i++){
        for (size_t q = 0; q < sizeof( frogs ) / sizeof( *frogs ); q++){
            if (frogs[q] == i){
                a[i] = std::numeric_limits<int>::max();
            }
        }
        for (size_t j = 0; j < sizeof( steps ) / sizeof( *steps ); j++){
            if (steps[j] <= number - i){
                int count;
                count = a[i] + danger[i + steps[j] - 1];
                if (count < a[i + steps[j]] && count > 0){
                    a[i + steps[j]] = count;
                }
            }
        }
    }
    if (a[number] == std::numeric_limits<int>::max()){
        return -1;
    }
    return a[number];
}

template<typename ValueType>
ValueType opt_damage_back_random(ValueType number, int steps[], int frogs[], int danger[]){
    int a[number + 1];
    for (int i = 0; i < number + 1; i++){
        a[i] = std::numeric_limits<int>::max();
    }
    a[0] = 0;
    for (size_t q = 0; q < sizeof( frogs ) / sizeof( *frogs ); q++){
        if (frogs[q] == number){
            return -1;
        }
    }
    for (int i = 0; i <= number; i++){
        for (size_t j = 0; j < sizeof( steps ) / sizeof( *steps ); j++){
            if (steps[j] <= i){
                for (size_t q = 0; q < sizeof( frogs ) / sizeof( *frogs ); q++){
                    if (frogs[q] == i - steps[j]){
                        a[i - steps[j]] = std::numeric_limits<int>::max();
                    }
                }
                int count;
                count = a[i - steps[j]] + danger[i - 1];
                if (count < a[i] && count > 0){
                    a[i] = count;
                }
            }
        }
    }
    if (a[number] == std::numeric_limits<int>::max()){
        return -1;
    }
    return a[number];
}
