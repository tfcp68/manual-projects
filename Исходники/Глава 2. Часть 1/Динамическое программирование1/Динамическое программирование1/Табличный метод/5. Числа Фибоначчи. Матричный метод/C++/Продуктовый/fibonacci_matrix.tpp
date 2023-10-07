#include <bits/stdc++.h>

using namespace std;


template<typename ValueType>
ValueType bin_pow(ValueType x, ValueType n) {
    if (-1 < x < 0 or 0 < x < 1) {
        return -1;
    }

    if (n < 0) {
        return -1;
    }

    if (n == 0) {
        return 1;
    }

    if (n == 1) {
        return x;
    }

    if (n % 2 != 0) {
        return bin_pow(x, n - 1) * x;
    }

    if (n % 2 == 0) {
        return bin_pow(x, n / 2) * bin_pow(x, n / 2);
    }
}

template<typename ValueType>
vector<std::vector<ValueType>> prod_matrix(const vector<std::vector<ValueType>> &a, const vector<std::vector<ValueType>> &b) {
    std::vector<std::vector<ValueType>> matrix_prod(2, std::vector<ValueType>(2, 0));
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            for (int r = 0; r < 2; r ++){
                matrix_prod[i][j] += a[i][r] * b[r][j];
            }
        }
    }

    return matrix_prod;
}

template<typename ValueType>
std::vector<std::vector<ValueType>> bin_pow_matrix(const std::vector<std::vector<ValueType>>& matrix,ValueType n) {
    if (n == 1) {
        return matrix;
    }

    if (n % 2 != 0) {
        std::vector<std::vector<ValueType>> temp_matrix = bin_pow_matrix(matrix, n - 1);
        return prod_matrix(temp_matrix, matrix);
    }

    if (n % 2 == 0) {
        std::vector<std::vector<ValueType>> temp_matrix = bin_pow_matrix(matrix, n / 2);
        return prod_matrix(temp_matrix, temp_matrix);
    }
}

template<typename ValueType>
ValueType fibonacci_matrix(ValueType n) {
    std::vector<std::vector<ValueType>> matrix(2, std::vector<ValueType>(2, 1));
    matrix[1][1] = 0;

    if (n < 0) {
        return -1;
    }

    if (n == 0) {
        return 0;
    }

    if (n == 1) {
        return 1;
    }

    std::vector<std::vector<ValueType>> bin_matrix = bin_pow_matrix(matrix, n - 1);
    ValueType fib = bin_matrix[0][0];

    return fib;
}