#include <vector>
#include <limits>

using namespace std;

int logical_tree(int n, int v, const vector<int> &a, const vector<int> &c) {
    int x = (n - 1) /2;
    vector<vector<int>> t(n, vector<int>(numeric_limits<int>::max(), 0));
    for (int i = 1; i <= n; i++){
        if (i > x) {
            t[i - 1][a[i - 1]] = 0;
        }
    }
    for (int i = x; i > 0; --i) {
        for (int t1 = 0; t1 < 2; ++t1) {
            for (int t2 = 0; t2 < 2; ++t2) {
                int t3;
                if (a[i - 1] == 1) {
                    t3 = (t1 && t2);
                } else {
                    t3 = (t1 || t2);
                }
                if (t[i - 1][t3] > t[2 * i - 1][t1] + t[2 * i][t2]) {
                    t[i - 1][t3] = t[2 * i - 1][t1] + t[2 * i][t2];
                }
            }
        }

        if (c[i - 1] == 1) {
            for (int t1 = 0; t1 < 2; ++t1) {
                for (int t2 = 0; t2 < 2; ++t2) {
                    int t3;
                    if (1 - a[i - 1] == 1) {
                        t3 = (t1 && t2);
                    } else {
                        t3 = (t1 || t2);
                    }
                    if (t[i - 1][t3] > t[2 * i - 1][t1] + t[2 * i][t2] + 1) {
                        t[i - 1][t3] = t[2 * i - 1][t1] + t[2 * i][t2] + 1;
                    }
                }
            }
        }
    }

    if (t[0][v] == numeric_limits<int>::max()) {
        return -1;
    }

    return t[0][v];
}