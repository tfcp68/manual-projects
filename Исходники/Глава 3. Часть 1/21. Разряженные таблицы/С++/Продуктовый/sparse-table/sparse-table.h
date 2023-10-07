#pragma once
#include <iostream>
#include <vector>
using namespace std;

template <typename TValue>
class SparseTable
{
    vector<vector<TValue>> ST;

public:
    void buildMinST(vector<TValue> &A);
    void buildMaxST(vector<TValue> &A);

    TValue findMin(int L, int R);
    TValue findMax(int L, int R);
};

#include "sparse-table.tpp"