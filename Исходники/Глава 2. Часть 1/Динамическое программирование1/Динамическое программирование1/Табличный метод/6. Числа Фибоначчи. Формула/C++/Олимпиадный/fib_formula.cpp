#include <bits/stdc++.h>
#include <cassert>

using namespace std;


int fib_formula(int n) {
    if (n < 0) {
        return -1;
    }
    double root_f = std::sqrt(5);
    double fie = (1 + root_f) / 2;
    double den = std::pow(fie, n) - std::pow(-fie, -n);
    double num = 2 * fie - 1;
    double fib = den / num;
    return static_cast<int>(fib);
}