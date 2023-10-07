#include <bits/stdc++.h>
#include <cassert>

using namespace std;

template<typename ValueType>
std::vector<ValueType> prefix_sum(const std::vector<ValueType>& arr) {
    std::vector<ValueType> prefix_arr(arr.size(), 0);
    prefix_arr[0] = arr[0];
    for (int k = 1; k < arr.size(); ++k) {
        prefix_arr[k] = prefix_arr[k - 1] + arr[k];
    }
    return prefix_arr;
}
