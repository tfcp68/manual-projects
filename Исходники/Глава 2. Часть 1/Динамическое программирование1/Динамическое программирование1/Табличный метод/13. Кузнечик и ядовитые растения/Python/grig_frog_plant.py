from math import inf


def optimal_damage_forward(damage, n, k, frogs):
    if n in frogs:
        return inf
    W = [0] + [inf] * n
    for i in range(0, n):
        if i in frogs:
            W[i] = inf
        r = min(k, n - i)
        for j in range(1, r + 1):
            count = W[i] + damage[i + j - 1]
            W[i+j] = min(count, W[i + j])
    return W[n]


def optimal_damage_back(damage, n, k, frogs):
    if n in frogs:
        return inf
    W = [0] + [inf] * n
    for i in range(0, n + 1):
        if i in frogs:
            W[i] = inf
        r = min(k, i)
        for j in range(1, r + 1):
            if i - j in frogs:
                W[i - j] = inf
            count = damage[i - 1] + W[i - j]
            W[i] = min(W[i], count)
    return W[n]


def output_way(W, damage, n, k):
    a = []
    r = min(k, n)
    for i in range(2, r + 1):
        if W[n] == W[n - i]+damage[n]:
            if n == 0:
                a.append(0)
                return a
            else:
                output_way(W, damage, n - i, k)
                a.append(n)
                return a
