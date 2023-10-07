#include <bits/stdc++.h>
#include <cassert>
#include <array>

using namespace std;

template<typename ValueType>
ValueType max_sum_enumeration(const std::vector<ValueType>& a, ValueType m){
    ValueType need_sum = -1;
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j <= i; j++) {
            ValueType temp_sum = 0;
            for (int k = j; k <= i; k++) {
                temp_sum += a[k];
            }
            if (need_sum < temp_sum && temp_sum <= m) {
                need_sum = temp_sum;
            }
        }
    }
    return need_sum;
}

template<typename ValueType>
ValueType max_sum_dp(const std::vector<ValueType>& arr, ValueType m) {
    ValueType need_sum = -1;
    std::vector<ValueType> prefix_arr(arr.size(), 0);
    prefix_arr[0] = arr[0];
    for (int k = 1; k < arr.size(); k++) {
        prefix_arr[k] = prefix_arr[k - 1] + arr[k];
    }
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j <= i; j++) {
            ValueType temp_sum = prefix_arr[i] - prefix_arr[j] + arr[j];
            if (need_sum < temp_sum && temp_sum <= m) {
                need_sum = temp_sum;
            }
        }
    }
    return need_sum;
}