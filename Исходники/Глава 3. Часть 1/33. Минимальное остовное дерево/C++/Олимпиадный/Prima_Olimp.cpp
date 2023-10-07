#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef set<int> si;

bool comp(vi edge1, vi edge2) {
    return edge1[2] < edge2[2];
}

vi r_min_edge(vector<vi> edges, si visit) {
    vector<vi> arr;
    for (vi edge : edges) {
        if ((visit.count(edge[0]) != 0) || (visit.count(edge[1]) != 0)) {
            if ((visit.count(edge[0])) == 0 || (visit.count(edge[1])) == 0) {
                arr.push_back(edge);
            }
        }
    };
    sort(arr.begin(), arr.end(), comp);
    vi min_edge = arr[0];
    arr.clear();
    return min_edge;
}

int prima(vector<vi> edges, si visit, int vtx) {
    int mst = 0;
    while (visit.size() != vtx) {
        vi min_edge = r_min_edge(edges, visit);
        mst += min_edge[2];
        visit.insert(min_edge[0]);
        visit.insert(min_edge[1]);
    };
    return mst;
}

int main() {
    vector<vi> edges = { {2, 5, 1}, {4, 3, 5}, {0, 1, 11}, {2, 0, 7}, {1, 3, 5}, {4, 2, 2}, {5, 3, 3} };
    si visit = { 0 };
    int vtx = 6;
    cout << prima(edges, visit, vtx);
    return 0;
}
