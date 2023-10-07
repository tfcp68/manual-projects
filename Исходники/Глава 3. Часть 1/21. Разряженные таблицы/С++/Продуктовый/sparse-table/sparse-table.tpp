#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include "sparse-table.h"

using namespace std;

template <typename TValue>
void SparseTable<TValue>::buildMinST(vector<TValue> &A)
{
    int LEN = A.size();
    int A_loglen = floor(log2(LEN));
    vector<vector<TValue>> ST(A_loglen + 1);
    ST[0] = A;

    for (int i = 1; i <= A_loglen; i++)
    {
        for (int j = 0; j + (1 << i) <= LEN; j++)
        {
            int SHIFT = 1 << (i - 1);
            TValue num1 = ST[i - 1][j];
            TValue num2 = ST[i - 1][j + SHIFT];
            TValue temp = min(num1, num2);
            ST[i].push_back(temp);
        }
    }

    this->ST = ST;
}

template <typename TValue>
void SparseTable<TValue>::buildMaxST(vector<TValue> &A)
{
    int LEN = A.size();
    int A_loglen = floor(log2(LEN));
    vector<vector<TValue>> ST(A_loglen + 1);
    ST[0] = A;

    for (int i = 1; i <= A_loglen; i++)
    {
        for (int j = 0; j + (1 << i) <= LEN; j++)
        {
            int SHIFT = 1 << (i - 1);
            TValue num1 = ST[i - 1][j];
            TValue num2 = ST[i - 1][j + SHIFT];
            TValue temp = max(num1, num2);
            ST[i].push_back(temp);
        }
    }

    this->ST = ST;
}

template <typename TValue>
TValue SparseTable<TValue>::findMin(int L, int R)
{
    int LEN = R - L + 1;
    int i = floor(log2(LEN));
    int SHIFT = (1 << i);
    TValue num1 = ST[i][L];
    TValue num2 = ST[i][R - SHIFT + 1];
    TValue res = min(num1, num2);

    return res;
}

template <typename TValue>
TValue SparseTable<TValue>::findMax(int L, int R)
{
    int LEN = R - L + 1;
    int i = floor(log2(LEN));
    int SHIFT = (1 << i);
    TValue num1 = ST[i][L];
    TValue num2 = ST[i][R - SHIFT + 1];
    TValue res = max(num1, num2);

    return res;
}