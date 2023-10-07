#include <bits/stdc++.h>


using namespace std;

template<typename ValueType>
ValueType grig_and_multiple_step_back(ValueType n, ValueType multi_k) {
    if (n < 0 or multi_k <= 0) {
        return -1;
    }
    if (n % multi_k != 0) {
        return 0;
    }
    std::vector<ValueType> arr(n + 1, 0);
    arr[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i / multi_k; j++) {
            arr[i] = arr[i] + arr[i - j * multi_k];
        }
    }
    return arr[n];
}

template<typename ValueType>
ValueType grig_and_multiple_step_forward(ValueType n, ValueType multi_k) {
    if (n < 0 or multi_k <= 0) {
        return -1;
    }
    if (n % multi_k != 0) {
        return 0;
    }
    std::vector<ValueType> arr(n + multi_k + 1, 0);
    arr[0] = 1;

    for (int i = 0; i <= n; i++) {
        for (int j = 1; j <= (n - i) / multi_k; j++) {
            arr[i + j * multi_k] = arr[i + j * multi_k] + arr[i];
        }
    }
    return arr[n];
}
