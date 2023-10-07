#include <bits/stdc++.h>

using namespace std;

int grig_back(int n){
    if(n < 0){
        return -1;
    }
    int a[n + 1] = {0};
    a[0] = 1;
    for (int i = 1; i < n + 1; i++){
        int r = min(2, i);
        for (int j = 1; j <= r; j++){
            a[i] = a[i] + a[i - j];
        }
    }
    return a[n];
}


int grig_forward(int n){
    if(n < 0){
        return -1;
    }
    int a[n + 1] = {0};
    a[0] = 1;
    for (int i = 0; i < n + 1; i++){
        a[i + 1] = a[i + 1] + a[i];
        a[i + 2] = a[i + 2] + a[i];
    }
    return a[n];
}
