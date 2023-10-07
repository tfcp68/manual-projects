#include <bits/stdc++.h>
#include <cassert>

using namespace std;

template<typename ValueType>
ValueType duo_one(ValueType n){
    if (n <= 0){
        return -1;
    }
    int arr[n + 1];
    for(int i = 0; i < n + 1; ++i)
        arr[i] = 0;
    arr[0] = 1;
    arr[1] = 2;
    for(int i = 2; i < n + 1; ++i){
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    return arr[n];
}
