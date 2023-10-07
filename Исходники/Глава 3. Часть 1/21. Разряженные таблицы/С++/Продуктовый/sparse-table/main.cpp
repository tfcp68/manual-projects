#include <bits/stdc++.h>
#include "sparse-table.tpp"

using namespace std;

int main()
{

    SparseTable<string> ST;
    vector<int> A = {1, 6, 4, 3, 7, 9, 7, 6, 5, 4};
    vector<float> B = {1.1, 6.2, 4.3, 3.4, 7.5, 9.6, 7.7, 6.8, 5.9, 4.1};
    vector<string> C = {"acb", "abc", "cab", "bca", "cba", "aab"};
    ST.buildMinST(C);
    auto res = ST.findMin(2, 4);
    cout << res << endl;
    ST.buildMaxST(C);
    res = ST.findMax(2, 4);
    cout << res;
    return 0;
}