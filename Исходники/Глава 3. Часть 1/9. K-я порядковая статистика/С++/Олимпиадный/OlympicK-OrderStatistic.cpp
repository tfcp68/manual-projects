#include <iostream>
#include <vector>

using namespace std;


typedef vector<int> vi;

int k_order_statistic(vi& arr, int k) {

    if (arr.size() == 1) {
        return arr[0];
    }

    int p = arr[arr.size() / 2];
    std::vector<int> l, r, equ;

    for (int x : arr) {

        if (x < p) {
            l.push_back(x);
        }

        else if (x > p) {
            r.push_back(x);
        }

        else {
            equ.push_back(x);
        }
    }

    if (k < l.size()) {
        return k_order_statistic(l, k);
    }

    else if (k < l.size() + equ.size()) {
        return equ[0];
    }

    else {
        return k_order_statistic(r, k - l.size() - equ.size());
    }
}

