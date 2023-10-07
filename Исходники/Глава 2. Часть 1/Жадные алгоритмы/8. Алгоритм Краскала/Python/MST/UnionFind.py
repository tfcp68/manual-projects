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
