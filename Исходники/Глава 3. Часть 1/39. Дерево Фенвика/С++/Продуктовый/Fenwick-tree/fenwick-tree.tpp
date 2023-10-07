#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include "fenwick-tree.h"

using namespace std;

template <typename TValue>
void FenwickTree<TValue>::modify(long long index, TValue delta)
{
    long long n = Fenwick.size();
    while (index < n)
    {
        Fenwick[index] += delta;
        index = index | (index + 1);
    }
}

template <typename TValue>
void FenwickTree<TValue>::build(vector<TValue> &A)
{
    long long n = A.size();
    Fenwick = vector<TValue>(n);
    for (long long i = 0; i < n; i++)
    {
        modify(i, A[i]);
    }
}

template <typename TValue>
FenwickTree<TValue>::FenwickTree(vector<TValue> &A)
{
    build(A);
}

template <typename TValue>
FenwickTree<TValue>::FenwickTree() {}

template <typename TValue>
TValue FenwickTree<TValue>::temp_sum(long long index)
{
    TValue res = 0;
    while (index >= 0)
    {
        res += Fenwick[index];
        index = (index & (index + 1)) - 1;
    }

    return res;
}

template <typename TValue>
TValue FenwickTree<TValue>::sum(long long l, long long r)
{
    TValue sum1 = temp_sum(r);
    TValue sum2 = temp_sum(l - 1);
    TValue res = sum1 - sum2;
    return res;
}