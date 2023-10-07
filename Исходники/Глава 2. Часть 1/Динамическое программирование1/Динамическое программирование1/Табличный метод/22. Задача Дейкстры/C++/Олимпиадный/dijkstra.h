#include <bits/stdc++.h>
#include <cassert>

using namespace std;

int dijkstra_back(int n){
    if(n <= 0){
        return -1;
    }
    int a[n + 1];
    a[1] = 1;
    for (int i = 2; i < n + 1; i++){
        if (i % 2 == 0){
            a[i] = a[i / 2];
        }
        else{
            a[i] = a[(i - 1) / 2] + a[(i - 1) / 2 + 1];
        }
    }
    return a[n];
}

int dijkstra_forward(int n){
    if(n <= 0){
        return -1;
    }
    int a[2 * n + 1];
    for (int i = 2; i < n + 1; i++){
        a[i] = 0;
    }
    a[1] = 1;
    for (int i = 1; i < n + 1; i++){
        a[2 * i] = a[i];
        a[2 * i + 1] = a[i] + a[i + 1];
    }
    return a[n];
}

