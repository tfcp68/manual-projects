#include <bits/stdc++.h>
#include <cassert>

using namespace std;

template<typename ValueType>
ValueType binomial_theorem_dp(ValueType n, ValueType k) {
    if (n <= 0 or k <= 0 or k > n) {
        return -1;
    }
    ValueType a[n + 1][n + 1];
    for (int j = 0; j < n + 1; ++j)
        for (int i = 0; i < n + 1; ++i)
            a[j][i] = 0;
    for (int i = 0; i < n + 1; ++i) {
        a[i][0] = 1;
        a[i][i] = 1;
    }
    for (int j = 1; j < n + 1; ++j)
        for (int i = 1; i < k + 1; ++i)
            a[j][i] = a[j - 1][i - 1] + a[j - 1][i];
    return a[n][k];
}