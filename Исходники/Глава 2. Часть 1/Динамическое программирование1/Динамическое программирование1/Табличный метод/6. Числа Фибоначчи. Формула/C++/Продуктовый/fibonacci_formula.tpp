#include <bits/stdc++.h>

using namespace std;


template<typename ValueType>
ValueType fibonacci_formula(ValueType n) {
    if (n < 0) {
        return -1;
    }
    ValueType root_five = std::sqrt(5);
    ValueType fie = (1 + root_five) / 2;
    ValueType den = std::pow(fie, n) - std::pow(-fie, -n);
    ValueType num = 2 * fie - 1;
    ValueType fib = den / num;
    return static_cast<ValueType>(fib);
}