#include <bits/stdc++.h>

using namespace std;

template<typename ValueType>
ValueType fibonacci_recursion(ValueType n) {
    if (n < 0) {
        return -1;
    }
    if (n == 0) {
        return 0;
    }
    if (n == 1 or n == 2) {
        return 1;
    }
    return fibonacci_recursion(n - 1) + fibonacci_recursion(n - 2);
}