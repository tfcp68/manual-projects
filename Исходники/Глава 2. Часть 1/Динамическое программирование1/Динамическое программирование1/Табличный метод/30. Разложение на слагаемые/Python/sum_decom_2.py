def euler_31_dp(n):
    if n <= 0:
        return -1
    coins = [1, 2, 5, 10, 20, 50, 100, 200]
    counters = [0] * (n + 1)
    counters[0] = 1
    for x in coins:
        for i in range(x, n + 1):
            counters[i] += counters[i - x]
    return counters[n]


def euler_31_enumeration(n):
    if n <= 0:
        return -1
    coins = [1, 2, 5, 10, 20, 50, 100, 200]
    counter = 0
    for a in range(0, n // coins[0] + 1):
        for b in range(0, n // coins[1] + 1):
            for c in range(0, n // coins[2] + 1):
                for d in range(0, n // coins[3] + 1):
                    for e in range(0, n // coins[4] + 1):
                        for f in range(0, n // coins[5] + 1):
                            for g in range(0, n // coins[6] + 1):
                                for k in range(0, n // coins[7] + 1):
                                    if (a * coins[0] + b * coins[1] + c * coins[2] + d * coins[3] + e * coins[4] +
                                        f * coins[5] + g * coins[6] + k * coins[7]) == n:
                                        counter += 1
    return counter
