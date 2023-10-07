from math import inf

def grig_random_step(n, steps):
    a = [1]
    for i in range(1, n+1):
        s = 0
        for j in steps:
            if j <= i:
                s += a[i - j]
        a.append(s)
    return a[n]


def optimal_damage_back_random(damage, n, steps, frogs):
    if n in frogs:
        return inf
    W = [0] + [inf] * n
    for i in range(0, n + 1):
        if i in frogs:
            W[i] = inf
        for j in steps:
            if j > i:
                continue
            if i - j in frogs:
                W[i - j] = inf
            W[i] = min(W[i], W[i - j] + damage[i - 1])
    return W[n]


def optimal_damage_forward_random(damage, n, steps, frogs):
    if n in frogs:
        return inf
    W = [0] + [inf] * n
    for i in range(0, n):
        if i in frogs:
            W[i] = inf
        for j in steps:
            if j > n - i:
                continue
            count = W[i] + damage[i + j - 1]
            W[i + j] = min(count, W[i + j])
            if i + j in frogs:
                W[i + j] = inf
    return W[n]