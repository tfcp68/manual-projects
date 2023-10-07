#include <bits/stdc++.h>
#include <cassert>

using namespace std;

template<typename ValueType>
ValueType biggest_square(std::vector<std::vector<ValueType>>& arr, ValueType n, ValueType m) {
    std::vector<std::vector<ValueType>> temp_arr(m, std::vector<ValueType>(n, 0));

    for (int i = 0; i < n; i++) {
        temp_arr[0][i] = arr[0][i];
    }

    for (int j = 0; j < m; j++) {
        temp_arr[j][0] = arr[j][0];
    }

    for (int j = 1; j < m; j++) {
        for (int i = 1; i < n; i++) {
            if (arr[j][i] == 0) {
                temp_arr[j][i] = arr[j][i];
            }
            else {
                temp_arr[j][i] = std::min({temp_arr[j - 1][i], temp_arr[j - 1][i - 1], temp_arr[j][i - 1] }) + 1;
            }
        }
    }

    ValueType max_square = 0;
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if (temp_arr[j][i] > max_square) {
                max_square = temp_arr[j][i];
            }
        }
    }

    return max_square;
}

template<typename ValueType>
ValueType bad_biggest_square(std::vector<std::vector<ValueType>>& arr, ValueType n, ValueType m) {
    std::vector<std::vector<ValueType>> temp_arr(m, std::vector<ValueType>(n, 0));
    for (int i = 0; i < n; i++) {
        temp_arr[m - 1][i] = arr[m - 1][i];
    }
    for (int j = 0; j < m; j++) {
        temp_arr[j][n - 1] = arr[j][n - 1];
    }
    for (int j = m - 2; j >= 0; j--) {
        for (int i = n - 2; i >= 0; i--) {
            if (arr[j][i] == 0) {
                temp_arr[j][i] = arr[j][i];
            }
            else {
                temp_arr[j][i] = std::min({temp_arr[j + 1][i], temp_arr[j + 1][i + 1], temp_arr[j][i + 1] }) + 1;
            }
        }
    }
    ValueType max_square = 0;
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if (temp_arr[j][i] > max_square) {
                max_square = temp_arr[j][i];
            }
        }
    }
    return max_square;
}
