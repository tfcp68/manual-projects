from math import inf


def deleting_sequence(arr: list):
    n = len(arr)
    if n <= 2:
        return 0

    d = [[0] * n for _ in range(n)]

    for len_ in range(2, n + 1):
        for i in range(0, n - len_):
            j = i + len_
            d[i][j] = inf
            for k in range(i + 1, j):
                v = d[i][k] + d[k][j] + arr[k] * (arr[i] + arr[j])
                d[i][j] = min(d[i][j], v)

    return d[0][n - 1]


# print(deleting_sequence([5, 1, 2, 7, 1]))
