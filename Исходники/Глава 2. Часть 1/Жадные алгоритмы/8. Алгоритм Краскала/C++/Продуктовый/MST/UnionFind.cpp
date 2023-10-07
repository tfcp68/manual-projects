#include "UnionFind.h"

UnionFind::UnionFind(int vertex) {
	rank.assign(vertex, 0);
	p.assign(vertex, 0);
	for (int i = 0; i < vertex; i++) p[i] = i;
}

int UnionFind::find_set(int v) {
	if (p[v] == v) { return v; }
	else { return find_set(p[v]); }
}

bool UnionFind::same_set(int v1, int v2) {
	return find_set(v1) == find_set(v2);
}

void UnionFind::union_set(int v1, int v2) {
	if (!same_set(v1, v2)) {
		int x = find_set(v1);
		int y = find_set(v2);
		if (rank[x] > rank[y]) { p[y] = x; }
		else {
			p[x] = y;
			if (rank[x] == rank[y]) rank[y]++;
		}
	}
}
