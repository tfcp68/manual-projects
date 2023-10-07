#include <bits/stdc++.h>
#include <cassert>

using namespace std;


int fib_ec_mem(int n) {
    if (n < 0) {
        return -1;
    }
    int a = 1;
    int b = 0;
    int c;
    for (int i = 1; i < n + 1; i++) {
        c = a + b;
        int a1, b1;
        a1 = b;
        b1 = c;
        a = a1;
        b = b1;
    }
    return b;
}