#include <bits/stdc++.h>

using namespace std;


template<typename ValueType>
ValueType fibonacci_dp_forward(ValueType n) {
    if (n < 0) {
        return -1;
    }
    ValueType arr[n + 1];
    for (int i = 0; i < (n + 2); i++) {
        arr[i] = 0;
    }
    arr[1] = 1;
    for (int i = 0; i < (n + 1); i++) {
        arr[i + 1] += arr[i];
        arr[i + 2] += arr[i];
    }
    return arr[n];
}
