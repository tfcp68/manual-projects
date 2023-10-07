#include <bits/stdc++.h>

using namespace std;

int lip_forward(int a[], int n){
    if (n == 1){
        return 1;
    }
    if (n <= 0){
        return 0;
    }
    int count_a[n];
    for (int i = 0; i< n; i++){
        count_a[i] = 1;
    }
    for (int i = n - 1; i >= 0; i--){
        for (int j = n - 1; j > i; j--) {
            if (a[j] > a[i] && count_a[j] + 1 > count_a[i]) {
                count_a[i] = count_a[j] + 1;
            }
        }
    }
    int max_count = 0;
    for (int i = 0; i< n; i++){
        if (max_count < count_a[i]){
            max_count = count_a[i];
        }
    }
    return max_count;
}

int lip_back(int a[], int n){
    if (n == 1){
        return 1;
    }
    if (n <= 0){
        return 0;
    }
    int count_a[n];
    for (int i = 0; i< n; i++){
        count_a[i] = 1;
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i] && count_a[j] + 1 > count_a[i]) {
                count_a[i] = count_a[j] + 1;
            }
        }
    }
    int max_count = 0;
    for (int i = 0; i< n; i++){
        if (max_count < count_a[i]){
            max_count = count_a[i];
        }
    }
    return max_count;
}