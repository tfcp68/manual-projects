#include <bits/stdc++.h>

using namespace std;


template<typename ValueType>
ValueType fibonacci_economy_memory(ValueType n) {
    if (n < 0) {
        return -1;
    }
    ValueType a = 1;
    ValueType b = 0;
    ValueType c;
    for (int i = 1; i < n + 1; i++) {
        c = a + b;
        ValueType a1, b1;
        a1 = b;
        b1 = c;
        a = a1;
        b = b1;
    }
    return b;
}