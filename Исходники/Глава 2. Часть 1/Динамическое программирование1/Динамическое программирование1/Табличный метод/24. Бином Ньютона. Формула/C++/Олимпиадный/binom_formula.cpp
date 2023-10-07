#include <bits/stdc++.h>
#include <cassert>

using namespace std;

int fact(int n) {
    if (n == 1) {
        return 1;
    }
    int answer = 1;
    for (int i = 2; i < n + 1; ++i) {
        answer *= i;
    }
    return answer;
}

int combination(int n, int k) {
    if (n <= 0 or k <= 0 or k > n) {
        return -1;
    }
    int numer = fact(n);
    int denom = fact(n - k) * fact(k);
    int answer = numer / denom;
    return answer;
}