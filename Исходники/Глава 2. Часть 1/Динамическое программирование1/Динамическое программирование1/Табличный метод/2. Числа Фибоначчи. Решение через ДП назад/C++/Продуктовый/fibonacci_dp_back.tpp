#include <bits/stdc++.h>

using namespace std;



template<typename ValueType>
ValueType fibonacci_dp_back(ValueType n) {
    if (n < 0) {
        return -1;
    }
    int arr[n + 1];
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i < n + 1; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    return arr[n];
}