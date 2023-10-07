#include <bits/stdc++.h>

using namespace std;

vector<int> A = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int n = A.size();
vector<int> F(n, 0);

void modify(int index, int delta)
{
    while (index < n)
    {
        F[index] += delta;
        index = index | (index + 1);
    }
}

int temp_sum(int index)
{
    int res = 0;
    while (index >= 0)
    {
        res += F[index];
        index = (index & (index + 1)) - 1;
    }

    return res;
}

int sum(int l, int r)
{
    int sum1 = temp_sum(r);
    int sum2 = temp_sum(l - 1);
    int res = sum1 - sum2;
    return res;
}

void build()
{
    for (int i = 0; i < n; i++)
    {
        modify(i, A[i]);
    }
}

int main()
{
    build();
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            cout << sum(i, j) << " ";
        }
        cout << endl;
    }
    return 0;
}