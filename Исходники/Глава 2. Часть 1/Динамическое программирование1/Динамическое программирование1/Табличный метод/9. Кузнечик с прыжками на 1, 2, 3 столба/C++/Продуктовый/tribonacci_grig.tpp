#include <bits/stdc++.h>


using namespace std;

template<typename ValueType>
ValueType grig_1_3_back(ValueType n) {
    if (n < 0) {
        return -1;
    }
    std::vector<ValueType> arr(n + 1, 0);
    arr[0] = 1;
    for (int i = 1; i <= n; i++) {
        int r = std::min(3, i);
        for (int j = 1; j <= r; j++) {
            arr[i] = arr[i] + arr[i - j];
        }
    }
    return arr[n];
}

template<typename ValueType>
ValueType grig_1_3_forward(ValueType n) {
    if (n < 0) {
        return -1;
    }
    std::vector<ValueType> arr(n + 3, 0);
    arr[0] = 1;
    for (int i = 0; i < n; i++) {
        arr[i + 1] = arr[i + 1] + arr[i];
        arr[i + 2] = arr[i + 2] + arr[i];
        arr[i + 3] = arr[i + 3] + arr[i];
    }
    return arr[n];
}
