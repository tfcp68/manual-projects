def grig_and_frogs_forward(n, k, frogs):
    if n < 0 or k < 0:
        return -1
    if 0 in frogs:
        return 0
    a = [1]
    a = a + [0] * (n + k + 1)
    for i in range(n + 1):
        for j in range(1, k + 1):

            if i + j not in frogs:
                a[i + j] += a[i]
    return a[n]


def grig_and_frogs_back(n, k, frogs):
    if n < 0 or k < 0:
        return -1
    if 0 in frogs:
        return 0
    a = [1]
    a = a + [0] * (n + k + 1)
    for i in range(n + 1):
        r = min(k, i)
        for j in range(1, r + 1):
            a[i] += a[i - j]
        if i in frogs:
            a[i] = 0
    return a[n]
