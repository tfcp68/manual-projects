from math import inf


class Minimum_removal:

    def __init__(self, a):
        self.a = a
        self.n = len(a)
        self.b = [[False] * self.n for _ in range(self.n)]
        self.f = [[0] * self.n for _ in range(self.n)]
        self.p = [[-1] * self.n for _ in range(self.n)]
        self.v = [[-1] * self.n for _ in range(self.n)]

    def printb(self, i, j):
        if self.p[i][j] == -1:
            return []
        arr = []
        arr += self.printb(i, self.p[i][j])
        arr += self.printb(self.p[i][j], j)
        arr += [self.p[i][j]]
        return arr

    def printf(self, i, j):
        if self.v[i][j] == -1:
            return self.printb(i, j)
        else:
            arr = []
            arr += self.printf(i, self.v[i][j])
            arr += self.printf(self.v[i][j], j)
        return arr

    def solve(self):
        for i in range(self.n - 1):
            self.b[i][i + 1] = True
        for len_ in range(2, self.n):
            for i in range(self.n - len_):
                j = i + len_
                self.b[i][j] = False
                for k in range(i + 1, j):
                    if self.b[i][k] and self.b[k][j] and ((self.a[k] < self.a[i] and self.a[k] < self.a[j]) or
                                                (self.a[k] > self.a[i] and self.a[k] > self.a[j])):
                        self.b[i][j] = True
                        self.p[i][j] = k

        for len_ in range(1, self.n):
            for i in range(self.n - len_):
                j = i + len_
                self.f[i][j] = inf
                if self.a[i] > self.a[j]:
                    continue
                if self.b[i][j]:
                    self.f[i][j] = j - i - 1
                for k in range(i + 1, j):
                    if self.f[i][k] + self.f[k][j] < self.f[i][j]:
                        self.f[i][j] = self.f[i][k] + self.f[k][j]
                        self.v[i][j] = k
        if self.f[0][self.n - 1] == inf:
            return -1
        else:
            return self.f[0][self.n - 1], self.printf(0, self.n - 1)


def minimum_removal(a: list):
    n = len(a)
    bool_ = [[False] * n for _ in range(n)]
    min_remove = [[inf] * n for _ in range(n)]

    for i in range(n - 1):
        bool_[i][i + 1] = True

    for len_ in range(2, n):
        for i in range(n - len_):
            j = i + len_
            for k in range(i + 1, j):
                if bool_[i][k] and bool_[k][j] and ((a[k] < a[i] and a[k] < a[j]) or (a[k] > a[i] and a[k] > a[j])):
                    bool_[i][j] = True

    for len_ in range(1, n):
        for i in range(n - len_):
            j = i + len_
            if a[i] > a[j]:
                continue
            if bool_[i][j]:
                min_remove[i][j] = j - i - 1
            for k in range(i + 1, j):
                if min_remove[i][k] + min_remove[k][j] < min_remove[i][j]:
                    min_remove[i][j] = min_remove[i][k] + min_remove[k][j]

    if min_remove[0][n - 1] == inf:
        return -1
    else:
        return min_remove[0][n - 1]


q = Minimum_removal([3, 2, 4, 8, 5])
print(q.solve())
print(minimum_removal([3, 2, 4, 8, 5]))
