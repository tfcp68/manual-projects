#include <bits/stdc++.h>

using namespace std;

template<typename ValueType>
ValueType grig_and_k_step_back(ValueType n, ValueType k) {
    if (n < 0 or k < 0) {
        return -1;
    }
    std::vector<ValueType> arr(n + 1, 0);
    arr[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= std::min(i, k); j++) {
            arr[i] = arr[i] + arr[i - j];
        }
    }
    return arr[n];
}

template<typename ValueType>
ValueType grig_and_k_step_forward(ValueType n, ValueType k) {
    if (n < 0 or k < 0) {
        return -1;
    }

    std::vector<ValueType> arr(n + k + 1, 0);
    arr[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            arr[i + j] = arr[i + j] + arr[i];
        }
    }
    return arr[n];
}

