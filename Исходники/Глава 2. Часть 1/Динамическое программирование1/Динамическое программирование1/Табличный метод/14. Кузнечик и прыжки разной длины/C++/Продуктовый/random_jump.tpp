#include <bits/stdc++.h>

using namespace std;

template<typename ValueType>
ValueType grig_and_any_steps(ValueType n, ValueType steps[]) {
    if (n < 0) {
        return -1;
    }

    std::vector<ValueType> a(n + 1, 0);
    a[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (size_t j = 0; j < sizeof(steps) / sizeof(*steps); j++) {
            if (steps[j] <= i) {
                a[i] = a[i] + a[i - steps[j]];
            }
        }
    }
    return a[n];
}
