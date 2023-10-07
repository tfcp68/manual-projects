#pragma once
#include <iostream>
#include <vector>
using namespace std;

template <typename TValue>
class FenwickTree
{
    vector<TValue> Fenwick;
    TValue temp_sum(long long index);

public:
    FenwickTree();
    FenwickTree(vector<TValue> &A);
    void build(vector<TValue> &A);
    void modify(long long index, TValue delta);
    TValue sum(long long l, long long r);
};

#include "fenwick-tree.tpp"