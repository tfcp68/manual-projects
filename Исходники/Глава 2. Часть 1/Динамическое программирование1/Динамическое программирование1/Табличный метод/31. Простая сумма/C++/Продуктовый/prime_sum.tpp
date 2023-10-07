#include <bits/stdc++.h>
#include <cassert>

using namespace std;

template<typename ValueType>
ValueType prime_sum(ValueType n){
    if (n <= 0){
        return -1;
    }

    if (n == 1){
        return 4;
    }

    ValueType prime[7] = {2, 3, 5, 7, 11, 13, 17};
    ValueType matrix_sum[n][10];

    for(int j = 0; j < n; ++j)
        for(int i = 0; i < 10; ++i)
            matrix_sum[j][i] = 0;

    ValueType prime_bool[19];

    for (int i = 0; i < 18; ++i){
        prime_bool[i] = 0;
    }

    for (int i = 0; i < 7; ++i){
        int k = prime[i];
        prime_bool[k] = 1;
    }

    for (int i = 1; i < 10; ++i){
        matrix_sum[0][i] = 1;
    }

    for(int j = 1; j < n; ++j){
        for(int i = 0; i < 10; ++i){
            matrix_sum[j][i] = 0;
            for (int k = 0; k < 10; ++k){
                if (prime_bool[k + i] == 1){
                    matrix_sum[j][i] += matrix_sum[j - 1][k];
                }
            }
        }
    }

    ValueType answer = 0;

    for(int i = 0; i < 10; ++i){
        answer += matrix_sum[n - 1][i];
    }

    return answer;
}