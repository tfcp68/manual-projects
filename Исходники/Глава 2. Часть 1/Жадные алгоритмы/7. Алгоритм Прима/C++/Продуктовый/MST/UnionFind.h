#ifndef UNIONFIND_H
#define UNIONFIND_H

#include <vector>

class UnionFind {
private:
	std::vector<int> p, rank;
public:
	UnionFind(int vertex);
	int find_set(int v);
	bool same_set(int v1, int v2);
	void union_set(int v1, int v2);
};

#endif