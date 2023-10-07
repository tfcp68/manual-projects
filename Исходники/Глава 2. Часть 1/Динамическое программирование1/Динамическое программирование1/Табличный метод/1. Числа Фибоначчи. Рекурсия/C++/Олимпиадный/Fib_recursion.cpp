#include <bits/stdc++.h>
#include <cassert>

using namespace std;

int fib_recurs(int n) {
    if (n < 0) {
        return -1;
    }
    if (n == 0) {
        return 0;
    }
    if (n == 1 or n == 2) {
        return 1;
    }
    return fib_recurs(n - 1) + fib_recurs(n - 2);
}