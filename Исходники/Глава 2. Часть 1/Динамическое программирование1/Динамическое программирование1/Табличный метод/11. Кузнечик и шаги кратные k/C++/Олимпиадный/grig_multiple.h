#include <bits/stdc++.h>


using namespace std;


int grig_and_multiple_step_back(int n, int multi_k) {
    if (n < 0 or multi_k <= 0) {
        return -1;
    }
    if (n % multi_k != 0) {
        return 0;
    }
    std::vector<int> a(n + 1, 0);
    a[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i / multi_k; j++) {
            a[i] = a[i] + a[i - j * multi_k];
        }
    }
    return a[n];
}

int grig_and_multiple_step_forward(int n, int multi_k) {
    if (n < 0 or multi_k <= 0) {
        return -1;
    }
    if (n % multi_k != 0) {
        return 0;
    }
    std::vector<int> a(n + multi_k + 1, 0);
    a[0] = 1;

    for (int i = 0; i <= n; i++) {
        for (int j = 1; j <= (n - i) / multi_k; j++) {
            a[i + j * multi_k] = a[i + j * multi_k] + a[i];
        }
    }
    return a[n];
}
