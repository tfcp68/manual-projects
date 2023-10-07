#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

#include "UnionFind.h"

using namespace std;

typedef vector<int> vi;
typedef set<int> si;

bool comp(vi edge1, vi edge2) {
    return edge1[2] < edge2[2];
}

int kraskal(vector<vi> edges, int vtx) {
    int mst = 0;
    UnionFind UF(vtx);
    sort(edges.begin(), edges.end(), comp);
    for (vi edge : edges) {
        if (!UF.same_set(edge[0], edge[1])) {
            mst += edge[2];
            UF.union_set(edge[0], edge[1]);
        }
    }
    return mst;
}

int main() {
    vector<vi> edges = { {2, 5, 1}, {4, 3, 5}, {0, 1, 11}, {2, 0, 7}, {1, 3, 5}, {4, 2, 2}, {5, 3, 3} };
    int vtx = 6;
    cout << kraskal(edges, vtx);
    return 0;
}
