#include <bits/stdc++.h>
#include <cassert>

using namespace std;



int biggest_square(vector<vector<int>>& a, int n, int m) {
    vector<vector<int>> b(m, vector<int>(n, 0));
    if (n <= 0 or m <= 0){
        return -1;
    }
    for (int i = 0; i < n; i++) {
        b[0][i] = a[0][i];
    }
    for (int j = 0; j < m; j++) {
        b[j][0] = a[j][0];
    }
    for (int j = 1; j < m; j++) {
        for (int i = 1; i < n; i++) {
            if (a[j][i] == 0) {
                b[j][i] = a[j][i];
            }
            else {
                b[j][i] = min({ b[j - 1][i], b[j - 1][i - 1], b[j][i - 1] }) + 1;
            }
        }
    }

    int max_square = 0;
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if (b[j][i] > max_square) {
                max_square = b[j][i];
            }
        }
    }

    return max_square;
}


int bad_biggest_square(vector<vector<int>>& a, int n, int m) {
    vector<vector<int>> b(m, vector<int>(n, 0));
    if (n <= 0 or m <= 0){
        return -1;
    }
    for (int i = 0; i < n; i++) {
        b[m - 1][i] = a[m - 1][i];
    }
    for (int j = 0; j < m; j++) {
        b[j][n - 1] = a[j][n - 1];
    }
    for (int j = m - 2; j >= 0; j--) {
        for (int i = n - 2; i >= 0; i--) {
            if (a[j][i] == 0) {
                b[j][i] = a[j][i];
            }
            else {
                b[j][i] = min({ b[j + 1][i], b[j + 1][i + 1], b[j][i + 1] }) + 1;
            }
        }
    }
    int max_square = 0;
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if (b[j][i] > max_square) {
                max_square = b[j][i];
            }
        }
    }
    return max_square;
}

