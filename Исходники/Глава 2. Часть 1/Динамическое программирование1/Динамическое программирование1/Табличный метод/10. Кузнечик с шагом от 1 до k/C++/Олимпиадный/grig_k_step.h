#include <bits/stdc++.h>


using namespace std;


int grig_and_k_step_back(int n, int k) {
    if (n < 0 or k < 0) {
        return -1;
    }
    std::vector<int> a(n + 1, 0);
    a[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= std::min(i, k); j++) {
            a[i] = a[i] + a[i - j];
        }
    }
    return a[n];
}

int grig_and_k_step_forward(int n, int k) {
    if (n < 0 or k < 0) {
        return -1;
    }
    std::vector<int> a(n + k + 1, 0);
    a[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            a[i + j] = a[i + j] + a[i];
        }
    }
    return a[n];
}

