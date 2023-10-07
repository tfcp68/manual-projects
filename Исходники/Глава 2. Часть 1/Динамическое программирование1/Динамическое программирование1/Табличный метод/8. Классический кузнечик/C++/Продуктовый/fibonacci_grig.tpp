#include <bits/stdc++.h>

using namespace std;

template<typename ValueType>
ValueType grig_back(ValueType n){
    if(n < 0){
        return -1;
    }
    ValueType arr[n + 1] = {0};
    arr[0] = 1;
    for (int i = 1; i < n + 1; i++){
        int r = min(2, i);
        for (int j = 1; j <= r; j++){
            arr[i] = arr[i] + arr[i - j];
        }
    }
    return arr[n];
}

template<typename ValueType>
ValueType grig_forward(ValueType n){
    if(n < 0){
        return -1;
    }
    ValueType arr[n + 1] = {0};
    arr[0] = 1;
    for (int i = 0; i < n + 1; i++){
        arr[i + 1] = arr[i + 1] + arr[i];
        arr[i + 2] = arr[i + 2] + arr[i];
    }
    return arr[n];
}

