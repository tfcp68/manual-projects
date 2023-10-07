#include <bits/stdc++.h>
#include <cassert>

using namespace std;

template<typename ValueType>
ValueType dijkstra_back(ValueType n){
    if(n < 0){
        return -1;
    }
    ValueType arr[n + 1];
    arr[1] = 1;
    for (int i = 2; i < n + 1; i++){
        if (i % 2 == 0){
            arr[i] = arr[i/2];
        }
        else{
            arr[i] = arr[(i - 1)/2] + arr[(i - 1)/2 + 1];
        }
    }
    return arr[n];
}

template<typename ValueType>
ValueType dijkstra_forward(ValueType n){
    if(n < 0){
        return -1;
    }
    ValueType arr[2 * n + 1];
    arr[1] = 1;
    for (int i = 2; i < n + 1; i++){
        arr[2 * i] = arr[i];
        arr[2 * i + 1] = arr[i] + arr[i+1];
    }
    return arr[n];
}
