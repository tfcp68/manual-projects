#include <bits/stdc++.h>
#include <cassert>

using namespace std;


int fib_dp_forward(int n) {
    if (n < 0) {
        return -1;
    }
    int a[n + 1];
    for (int i = 0; i < (n + 2); i++) {
        a[i] = 0;
    }
    a[1] = 1;
    for (int i = 0; i < (n + 1); i++) {
        a[i + 1] += a[i];
        a[i + 2] += a[i];
    }
    return a[n];
}