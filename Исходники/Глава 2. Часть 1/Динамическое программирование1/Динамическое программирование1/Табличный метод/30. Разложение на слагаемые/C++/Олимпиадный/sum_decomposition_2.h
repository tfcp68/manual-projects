#include <bits/stdc++.h>

using namespace std;


int euler_31_dp(int n) {
    if (n <= 0){
        return -1;
    }
    int sums[n + 1];
    int coins[8] = {1, 2, 5, 10, 20, 50, 100, 200};
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

int euler_31_enumeration(int n) {
    if (n <= 0){
        return -1;
    }
    int coins[8]={1, 2, 5, 10, 20, 50, 100, 200}, counter=1;
    for(int a=0; a<=200; ++a){
        for(int b=0; b<=100; ++b){
            for(int c=0; c<=40; ++c){
                for(int d=0; d<=20; ++d){
                    for(int e=0; e<=10; ++e){
                        for(int f=0; f<=4; ++f){
                            for(int g=0; g<=2; ++g){
                                if((a*coins[0]+b*coins[1]+c*coins[2]+d*coins[3]+e*coins[4]+f*coins[5]+g*coins[6]) == n){
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