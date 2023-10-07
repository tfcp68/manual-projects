#include <bits/stdc++.h>
#include <cassert>

using namespace std;

int prime_sum(int n){
    if (n <= 0){
        return -1;
    }
    if (n == 1){
        return 4;
    }
    int p[7] = {2, 3, 5, 7, 11, 13, 17};
    int m_sum[n][10];
    for(int j = 0; j < n; ++j)
        for(int i = 0; i < 10; ++i)
            m_sum[j][i] = 0;
    int b[19];
    for (int i = 0; i < 18; ++i){
        b[i] = 0;
    }
    for (int i = 0; i < 7; ++i){
        int k = p[i];
        b[k] = 1;
    }
    for (int i = 1; i < 10; ++i){
        m_sum[0][i] = 1;
    }
    for(int j = 1; j < n; ++j){
        for(int i = 0; i < 10; ++i){
            m_sum[j][i] = 0;
            for (int k = 0; k < 10; ++k){
                if (b[k + i] == 1){
                    m_sum[j][i] += m_sum[j - 1][k];
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < 10; ++i){
        ans += m_sum[n - 1][i];
    }
    return ans;
}
