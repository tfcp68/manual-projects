def grig_and_multiple_step_forward(n, multi_k):
    if n < 0 or multi_k < 0:
        return -1
    if n % multi_k != 0:
        return 0
    a = [1]
    a = a + [0] * (n + multi_k + 1)
    for i in range(n + 1):
        for j in range(1, (n - i) // multi_k + 1):
            a[i + j * multi_k] += a[i]
    return a[n]


def grig_and_multiple_step_back(n, multi_k):
    if n < 0 or multi_k < 0:
        return -1
    if n % multi_k != 0:
        return 0
    a = [1]
    for i in range(1, n + 1):
        s = 0
        for j in range(1, i // multi_k + 1):
            s += a[i - j * multi_k]
        a.append(s)
    return a[n]
