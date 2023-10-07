#include <bits/stdc++.h>
#include <cassert>

using namespace std;

std::vector<int> prefix_sum(const std::vector<int>& a) {
    std::vector<int> pref_a(a.size(), 0);
    pref_a[0] = a[0];
    for (int k = 1; k < a.size(); ++k) {
        pref_a[k] = pref_a[k - 1] + a[k];
    }
    return pref_a;
}