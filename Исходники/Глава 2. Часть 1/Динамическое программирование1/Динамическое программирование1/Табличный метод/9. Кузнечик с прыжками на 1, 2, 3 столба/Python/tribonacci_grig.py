def grig_1_3_back(n):
    if n < 0:
        return -1
    a = [1] + [0] * n
    for i in range(1, n + 1):
        r = min(3, i)
        for j in range(1, r + 1):
            a[i] += a[i - j]
    return a[n]


def grig_1_3_forward(n):
    if n < 0:
        return -1
    a = [1]
    a = a + [0] * (n + 3)
    for i in range(n):
        a[i + 1] = a[i + 1] + a[i]
        a[i + 2] = a[i + 2] + a[i]
        a[i + 3] = a[i + 3] + a[i]
    return a[n]
