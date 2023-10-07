#include <vector>
#include <limits>

template<typename ValueType>
int logical_tree(int n, int v, const std::vector<int> &a, const std::vector<int> &c) {
    int x = (n - 1) /2;
    int INF = std::numeric_limits<int>::max();

    std::vector<std::vector<int>> tree(n, std::vector<int>(INF, 0));
    for (int i = 1; i <= n; i++){
        if (i > x) {
            tree[i - 1][a[i - 1]] = 0;
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
                if (tree[i - 1][t3] > tree[2 * i - 1][t1] + tree[2 * i][t2]) {
                    tree[i - 1][t3] = tree[2 * i - 1][t1] + tree[2 * i][t2];
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
                    if (tree[i - 1][t3] > tree[2 * i - 1][t1] + tree[2 * i][t2] + 1) {
                        tree[i - 1][t3] = tree[2 * i - 1][t1] + tree[2 * i][t2] + 1;
                    }
                }
            }
        }
    }

    if (tree[0][v] == INF) {
        return -1;
    }

    return tree[0][v];
}
