#include <bits/stdc++.h>
#include "fenwick-tree.tpp"

using namespace std;

int main()
{
    vector<float> A = {1, 2, 3, 4.8, 5.5, 6, 7, 8, 9, 10};
    FenwickTree<float> Fenwick;
    Fenwick.build(A);
    float res = Fenwick.sum(3, 7);
    cout << res;
    return 0;
}