#include <bits/stdc++.h>
#include <cassert>

using namespace std;

template<typename ValueType>
ValueType fact(ValueType n) {
    if (n == 1) {
        return -1;
    }
    int answer = 1;
    for (int i = 2; i < n + 1; ++i) {
        answer *= i;
    }
    return answer;
}

template<typename ValueType>
ValueType combination(ValueType n, ValueType k) {
    if (n <= 0 or k <= 0) {
        return -1;
    }
    int numerator = fact(n);
    int denominator = fact(n - k) * fact(k);
    int answer = numerator / denominator;
    return answer;
}