#include <bits/stdc++.h>

using namespace std;

template<typename ValueType>
ValueType euler_31_dp(ValueType n) {
    ValueType sums[n + 1];
    ValueType coins[8]={1, 2, 5, 10, 20, 50, 100, 200};
    for (int i = 0; i <= n; i++){
        sums[i] = 0;
    }
    sums[0] = 1;
    for (int i: coins){
        for (int j = i; j <= n; j++){
            sums[j] += sums[j - i];
        }
    }
    return sums[n];
}

template<typename ValueType>
ValueType euler_31_enumeration(ValueType n) {
    ValueType coins[8]={1, 2, 5, 10, 20, 50, 100, 200}, counter=0;
    for(int a=0; a<=n/coins[0]; ++a){
        for(int b=0; b<=n/coins[1]; ++b){
            for(int c=0; c<=n/coins[2]; ++c){
                for(int d=0; d<=n/coins[3]; ++d){
                    for(int e=0; e<=n/coins[4]; ++e){
                        for(int f=0; f<=n/coins[5]; ++f){
                            for(int g=0; g<=n/coins[6]; ++g){
                                for(int k=0; k<=n/coins[7]; ++k){
                                    if((a*coins[0]+b*coins[1]+c*coins[2]+d*coins[3]+e*coins[4]+f*coins[5]+g*coins[6]+k*coins[7]) == n){
                                        ++counter;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return counter;
}
