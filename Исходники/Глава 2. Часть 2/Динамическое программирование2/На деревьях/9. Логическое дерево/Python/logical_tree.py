from math import inf

#
# def change(i, op, cost, f):
#     for t1 in range(2):
#         for t2 in range(2):
#             if op == 1:
#                 t3 = (t1 and t2)
#             else:
#                 t3 = (t1 or t2)
#             if f[i][t3] > f[2*i][t1] + f[2*i + 1][t2] + cost:
#                 f[i][t3] = f[2 * i][t1] + f[2 * i + 1][t2] + cost
#
#
# def solve():
#     n, v = map(int, input().split())
#     x = (n - 1) / 2
#     a = [0] * n
#     c = [0] * n
#     f = [[0] * 2 for _ in range(n)]
#     for i in range(n):
#         f[i][0] = inf
#         f[i][1] = inf
#         if i <= x:
#             a[i], c[i] = map(int, input().split())
#         else:
#             a[i] = int(input())
#             f[i][a[i]] = 0
#
#     for i in range(x, 1, -1):
#         change(i, a[i], 0, f)
#         if c[i] == 1:
#             change(i, 1 - a[i], 1, f)
#     if f[1][v] == inf:
#         return 'Impossible'
#     return f[1][v]


# def logical_tree():
#     n, v = map(int, input().split())
#     x = (n - 1) // 2
#     a = [0] * n
#     c = [0] * n
#     f = [[0] * 2 for _ in range(n)]
#     for i in range(1, n + 1):
#         f[i - 1][0] = inf
#         f[i - 1][1] = inf
#         if i <= x:
#             a[i - 1], c[i - 1] = map(int, input().split())
#         else:
#             a[i - 1] = int(input())
#             f[i - 1][a[i - 1]] = 0
#
#     for i in range(x, 0, -1):
#         for t1 in range(2):
#             for t2 in range(2):
#                 if a[i - 1] == 1:
#                     t3 = (t1 and t2)
#                 else:
#                     t3 = (t1 or t2)
#                 if f[i - 1][t3] > f[2 * i - 1][t1] + f[2 * i][t2]:
#                     f[i - 1][t3] = f[2 * i - 1][t1] + f[2 * i][t2]
#
#         if c[i - 1] == 1:
#
#             for t1 in range(2):
#                 for t2 in range(2):
#                     if 1 - a[i - 1] == 1:
#                         t3 = (t1 and t2)
#                     else:
#                         t3 = (t1 or t2)
#                     if f[i - 1][t3] > f[2 * i - 1][t1] + f[2 * i][t2] + 1:
#                         f[i - 1][t3] = f[2 * i - 1][t1] + f[2 * i][t2] + 1
#
#     if f[0][v] == inf:
#         return 'Impossible'
#
#     return f[0][v]

def logical_tree(n: int, v: int, a: list, c: list):
    x = (n - 1) // 2

    tree = [[inf] * 2 for _ in range(n)]
    for i in range(1, n + 1):
        if i > x:
            tree[i - 1][a[i - 1]] = 0

    for i in range(x, 0, -1):
        for t1 in range(2):
            for t2 in range(2):
                if a[i - 1] == 1:
                    t3 = (t1 and t2)
                else:
                    t3 = (t1 or t2)
                if tree[i - 1][t3] > tree[2 * i - 1][t1] + tree[2 * i][t2]:
                    tree[i - 1][t3] = tree[2 * i - 1][t1] + tree[2 * i][t2]

        if c[i - 1] == 1:
            for t1 in range(2):
                for t2 in range(2):
                    if 1 - a[i - 1] == 1:
                        t3 = (t1 and t2)
                    else:
                        t3 = (t1 or t2)
                    if tree[i - 1][t3] > tree[2 * i - 1][t1] + tree[2 * i][t2] + 1:
                        tree[i - 1][t3] = tree[2 * i - 1][t1] + tree[2 * i][t2] + 1

    if tree[0][v] == inf:
        return -1

    return tree[0][v]


n = 11
v = 1
a = [1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1]
c = [0, 0, 1, 1, 1]

print(logical_tree(n, v, a, c))
