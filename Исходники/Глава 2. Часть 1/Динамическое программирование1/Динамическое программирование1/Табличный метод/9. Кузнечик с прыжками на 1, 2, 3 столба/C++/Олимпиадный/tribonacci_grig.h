#include <bits/stdc++.h>


using namespace std;


int grig_1_3_back(int n) {
    if (n < 0) {
        return -1;
    }
    std::vector<int> a(n + 1, 0);
    a[0] = 1;
    for (int i = 1; i <= n; i++) {
        int r = std::min(3, i);
        for (int j = 1; j <= r; j++) {
            a[i] = a[i] + a[i - j];
        }
    }
    return a[n];
}

int grig_1_3_forward(int n) {
    if (n < 0) {
        return -1;
    }
    std::vector<int> a(n + 3, 0);
    a[0] = 1;
    for (int i = 0; i < n; i++) {
        a[i + 1] = a[i + 1] + a[i];
        a[i + 2] = a[i + 2] + a[i];
        a[i + 3] = a[i + 3] + a[i];
    }
    return a[n];
}