def grig_and_k_step_forward(n, k):
    if n < 0 or k < 0:
        return -1
    a = [1]
    a = a + [0] * (n + k + 1)
    for i in range(n+1):
        for j in range(1, k + 1):
            a[i + j] += a[i]
    return a[n]


def grig_and_k_step_back(n, k):
    if n < 0 or k < 0:
        return -1
    a = [1]
    for i in range(1, n + 1):
        s = 0
        r = min(k, i)
        for j in range(1, r + 1):
            s += a[i - j]
        a.append(s)
    return a[n]
