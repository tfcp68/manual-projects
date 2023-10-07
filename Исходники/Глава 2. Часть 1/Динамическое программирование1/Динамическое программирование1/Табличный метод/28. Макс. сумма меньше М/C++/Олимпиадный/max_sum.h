#include <bits/stdc++.h>
#include <cassert>
#include <array>

using namespace std;


int max_sum_enumeration(const vector<int>& a, int m){
    int need_s = -1;
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j <= i; j++) {
            int s = 0;
            for (int k = j; k <= i; k++) {
                s += a[k];
            }
            if (need_s < s && s <= m) {
                need_s = s;
            }
        }
    }
    return need_s;
}

int max_sum_dp(const vector<int>& a, int m) {
    int n_s = -1;
    vector<int> pr_a(a.size(), 0);
    pr_a[0] = a[0];
    for (int k = 1; k < a.size(); k++) {
        pr_a[k] = pr_a[k - 1] + a[k];
    }
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j <= i; j++) {
            int t_s = pr_a[i] - pr_a[j] + a[j];
            if (n_s < t_s && t_s <= m) {
                n_s = t_s;
            }
        }
    }
    return n_s;
}
