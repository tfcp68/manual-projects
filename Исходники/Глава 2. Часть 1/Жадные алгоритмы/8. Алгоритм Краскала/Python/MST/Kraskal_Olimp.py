
class UnionFind:
    def __init__(self, n):
        self.p = [i for i in range(n)]
        self.rank = [0] * n

    def find_set(self, v):
        if self.p[v] == v:
            return v
        return self.find_set(self.p[v])

    def same_set(self, v1, v2):
        return self.find_set(self.p[v1]) == self.find_set(self.p[v2])

    def union_set(self, v1, v2):
        x = self.find_set(v1)
        y = self.find_set(v2)
        if self.rank[x] > self.rank[y]:
            self.p[y] = x
        else:
            self.p[x] = y
            if self.rank[x] == self.rank[y]:
                self.rank[y] += 1


edges = [(2, 5, 1), (4, 3, 5), (0, 1, 11), (2, 0, 7), (1, 3, 5), (4, 2, 2), (5, 3, 3)]
V = 6


def kraskal(edges, V):
    mst = 0
    UF = UnionFind(V)
    edges = sorted(edges, key=lambda x: x[2])
    for edge in edges:
        if not(UF.same_set(edge[0], edge[1])):
            mst += edge[2]
            UF.union_set(edge[0], edge[1])
    return mst


print(kraskal(edges, V))

