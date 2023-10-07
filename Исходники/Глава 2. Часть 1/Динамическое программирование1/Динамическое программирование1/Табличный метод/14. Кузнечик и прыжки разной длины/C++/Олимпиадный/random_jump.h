#include <bits/stdc++.h>

using namespace std;


int grig_and_any_steps(int n, int s[]) {
    if (n < 0) {
        return -1;
    }

    std::vector<int> a(n + 1, 0);
    a[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (size_t j = 0; j < sizeof(s) / sizeof(*s); j++) {
            if (s[j] <= i) {
                a[i] = a[i] + a[i - s[j]];
            }
        }
    }

    return a[n];
}
