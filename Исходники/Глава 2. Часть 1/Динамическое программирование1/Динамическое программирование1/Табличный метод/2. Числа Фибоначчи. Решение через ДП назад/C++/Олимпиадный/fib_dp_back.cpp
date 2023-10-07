#include <bits/stdc++.h>
#include <cassert>

using namespace std;


int fib_dp_back(int n) {
    if (n < 0) {
        return -1;
    }
    int a[n + 1];
    a[0] = 0;
    a[1] = 1;
    for (int i = 2; i < n + 1; i++) {
        a[i] = a[i - 1] + a[i - 2];
    }
    return a[n];
}