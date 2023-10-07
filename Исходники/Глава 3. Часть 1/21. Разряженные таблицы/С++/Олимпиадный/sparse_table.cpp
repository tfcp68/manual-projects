#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> sparse_table(vector<int> &A)
{
    int LOG = floor(log2(A.size()));
    vector<vector<int>> ST(LOG + 1);
    ST[0] = A;

    for (int i = 1; i <= LOG; i++)
    {
        for (int j = 0; j + (1 << i) <= A.size(); j++)
        {
            ST[i].push_back(min(ST[i - 1][j], ST[i - 1][j + (1 << (i - 1))]));
        }
    }

    return ST;
}

int find_min(int L, int R, vector<vector<int>> &ST)
{
    int i = floor(log2(R - L + 1));
    return min(ST[i][L], ST[i][R - (1 << i) + 1]);
}

int main()
{
    vector<int> A = {4, 8, 15, 16, 23, 42, 8, 3, 16, 20};
    vector<int> B = {3, 8, 6, 4, 2, 5, 9, 6, 7, 1, 55, 2, 5, 8, -5};
    auto ST = sparse_table(A);

    for (int i = 0; i < A.size(); i++)
    {
        for (int j = i + 1; j < A.size(); j++)
        {
            int res = find_min(i, j, ST);
            cout << res << " ";
        }
        cout << endl;
    }
    return 0;
}