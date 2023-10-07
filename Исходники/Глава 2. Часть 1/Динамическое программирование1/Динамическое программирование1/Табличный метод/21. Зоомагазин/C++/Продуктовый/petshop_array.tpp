#include <bits/stdc++.h>

using namespace std;

template<typename ValueType>
ValueType petshop_array(ValueType n){
    if(n < 0){
        return -1;
    }
    if(n == 0){
        return 0;
    }
    if(n < 3){
        return pow(2, n);
    }
    int arr[n + 3];
    for(int i = 0; i <= n; i++){
        arr[i] = 0;
    }
    for(int i = 3; i <= n; i++){
        arr[i] = arr[i - 1] + pow(2, i - 3);
    }
    int answer;
    answer = pow(2, n) - arr[n];
    return answer;
}
