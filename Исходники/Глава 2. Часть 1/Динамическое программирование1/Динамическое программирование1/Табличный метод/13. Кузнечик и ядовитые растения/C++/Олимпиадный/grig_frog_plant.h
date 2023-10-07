#include <bits/stdc++.h>

using namespace std;


int optimal_damage_forward(int n, int k, int f[], int d[]) {
    int a[n + 1];
    for (int i = 0; i < n + 1; i++) {
        a[i] = std::numeric_limits<int>::max();
    }
    a[0] = 0;
    for (size_t q = 0; q <= sizeof(f) / sizeof(*f); q++) {
        if (f[q] == n) {
            return -1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (size_t q = 0; q <= sizeof(f) / sizeof(*f); q++) {
            if (f[q] == i) {
                a[i] = std::numeric_limits<int>::max();
            }
        }
        int r;
        if (k <= (n - i)) {
            r = k;
        }
        if (k > (n - i)) {
            r = n - i;
        }
        for (int j = 1; j < r + 1; j++) {
            int count;
            count = a[i] + d[i + j - 1];
            if (count < a[i + j] && count > 0) {
                a[i + j] = count;
            }
        }
    }
    if (a[n] == std::numeric_limits<int>::max()) {
        return -1;
    }
    return a[n];
}


int optimal_damage_back(int n, int k, int f[], int d[]){
    int a[n + 1];
    for (int i = 0; i < n + 1; i++){
        a[i] = std::numeric_limits<int>::max();
    }
    a[0] = 0;
    for (size_t q = 0; q <= sizeof( f ) / sizeof( *f ); q++){
        if (f[q] == n){
            return -1;
        }
    }
    for (int i = 1; i < n + 1; i++){
        int r;
        if (k <= i){
            r = k;
        }
        if (k > i){
            r = i;
        }
        for (int j = 1; j < r + 1; j++){
            for (size_t q = 0; q <= sizeof( f ) / sizeof( *f ); q++){
                if (f[q] == i - j){
                    a[i - j] = std::numeric_limits<int>::max();
                }
            }
            int count;
            count = a[i - j] + d[i - 1];
            if (count < a[i] && count > 0){
                a[i] = count;
            }
        }
    }
    if (a[n] == std::numeric_limits<int>::max()){
        return -1;
    }
    return a[n];
}

int output_way(int *W, int *d, int n, int k){
    if (n == 0){
        cout << 0;
    }
    int r;
    if (k > n){
        r = n;
    }
    if (k <= n){
        r = k;
    }
    for (int i = 1; i < r+1; i++){
        if (W[n] == W[n - i] + d[n - 1]){
            if (n != 0){
                output_way(W, d, n - i, k);
                cout << " " << n;
            }
        }
    }
}