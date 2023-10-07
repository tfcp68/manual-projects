#include <bits/stdc++.h>
#include <cassert>

using namespace std;



int bin_pow(int x, int n) {
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

std::vector<std::vector<int>> prod_matrix(const std::vector<std::vector<int>>& a, const std::vector<std::vector<int>>& b) {
    std::vector<std::vector<int>> m_prod(2, std::vector<int>(2, 0));
    m_prod[0][0] = a[0][0] * b[0][0] + a[0][1] * b[1][0];
    m_prod[0][1] = a[0][0] * b[0][1] + a[0][1] * b[1][1];
    m_prod[1][0] = a[1][0] * b[0][0] + a[1][1] * b[1][0];
    m_prod[1][1] = a[1][0] * b[0][1] + a[1][1] * b[1][1];
    return m_prod;
}

std::vector<std::vector<int>> bin_pow_matrix(const std::vector<std::vector<int>>& m, int n) {
    if (n == 1) {
        return m;
    }

    if (n % 2 != 0) {
        std::vector<std::vector<int>> temp_m = bin_pow_matrix(m, n - 1);
        return prod_matrix(temp_m, m);
    }

    if (n % 2 == 0) {
        std::vector<std::vector<int>> temp_m = bin_pow_matrix(m, n / 2);
        return prod_matrix(temp_m, temp_m);
    }
}

int fib_matrix(int n) {
    std::vector<std::vector<int>> m(2, std::vector<int>(2, 1));
    m[1][1] = 0;
    if (n < 0) {
        return -1;
    }
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    std::vector<std::vector<int>> bin_matrix = bin_pow_matrix(m, n - 1);
    int fib = bin_matrix[0][0];
    return fib;
}