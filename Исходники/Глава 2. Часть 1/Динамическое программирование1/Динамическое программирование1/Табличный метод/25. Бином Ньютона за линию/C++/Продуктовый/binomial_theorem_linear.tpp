#include <bits/stdc++.h>
#include <cassert>

using namespace std;

template<typename ValueType>
ValueType binomial_theorem_linear_n(ValueType n, ValueType k) {
    if (n <= 0 or k <= 0 or k > n) {
        return -1;
    }
    ValueType arr[n + 1];
    for (int i = 0; i <= n; i++) {
        arr[i] = 0;
    }
    arr[k] = 1;
    for (int i = k + 1; i <= n; i++) {
        arr[i] = arr[i - 1] * i / (i - k);
    }
    return arr[n];
}


template<typename ValueType>
ValueType binomial_theorem_linear_k(ValueType n, ValueType k) {
    if (n <= 0 or k <= 0 or k > n) {
        return -1;
    }
    ValueType arr[k + 1];
    for (int i = 0; i <= k; i++) {
        arr[i] = 0;
    }
    arr[0] = 1;
    for (int i = 1; i <= k + 1; i++) {
        arr[i] = arr[i - 1] * (n - i + 1) / i;
    }
    return arr[k];
}