#include <bits/stdc++.h>
#include <cassert>

using namespace std;


int opt_damage_forward_random(int n, int s[ ], int f[], int d[]){
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
    for (int i = 0; i < n; i++){
        for (size_t q = 0; q < sizeof( f ) / sizeof( *f ); q++){
            if (f[q] == i){
                a[i] = std::numeric_limits<int>::max();
            }
        }
        for (size_t j = 0; j < sizeof( s ) / sizeof( *s ); j++){
            if (s[j] <= n - i){
                int count;
                count = a[i] + d[i + s[j] - 1];
                if (count < a[i + s[j]] && count > 0){
                    a[i + s[j]] = count;
                }
            }
        }
    }
    if (a[n] == std::numeric_limits<int>::max()){
        return -1;
    }
    return a[n];
}


int opt_damage_back_random(int n, int s[], int f[], int d[]){
    int a[n + 1];
    for (int i = 0; i < n + 1; i++){
        a[i] = std::numeric_limits<int>::max();
    }
    a[0] = 0;
    for (size_t q = 0; q < sizeof( f ) / sizeof( *f ); q++){
        if (f[q] == n){
            return -1;
        }
    }
    for (int i = 0; i <= n; i++){
        for (size_t j = 0; j < sizeof( s ) / sizeof( *s ); j++){
            if (s[j] <= i){
                for (size_t q = 0; q < sizeof( f ) / sizeof( *f ); q++){
                    if (f[q] == i - s[j]){
                        a[i - s[j]] = std::numeric_limits<int>::max();
                    }
                }
                int count;
                count = a[i - s[j]] + d[i - 1];
                if (count < a[i] && count > 0){
                    a[i] = count;
                }
            }
        }
    }
    if (a[n] == std::numeric_limits<int>::max()){
        return -1;
    }
    return a[n];
}