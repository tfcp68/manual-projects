#include <bits/stdc++.h>
#include <cassert>

using namespace std;

int binomial_theorem_linear_n(int n, int k) {
    if (n <= 0 or k <= 0 or k > n) {
        return -1;
    }
    int a[n + 1];
    for (int i = 0; i <= n; i++) {
        a[i] = 0;
    }
    a[k] = 1;
    for (int i = k + 1; i <= n; i++) {
        a[i] = a[i - 1] * i / (i - k);
    }
    return a[n];
}

int binomial_theorem_linear_k(int n, int k) {
    if (n <= 0 or k <= 0 or k > n) {
        return -1;
    }
    int a[k + 1];
    for (int i = 0; i <= k; i++) {
        a[i] = 0;
    }
    a[0] = 1;
    for (int i = 1; i <= k + 1; i++) {
        a[i] = a[i - 1] * (n - i + 1) / i;
    }
    return a[k];
}