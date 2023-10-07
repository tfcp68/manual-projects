def binomial_theorem_dp(n, k):
    if n <= 0 or k <= 0 or k > n:
        return -1
    a = [[0 for _ in range(n + 1)] for _ in range(n + 1)]
    for i in range(n):
        a[i][0] = 1
        a[i][i] = 1
    for i in range(1, n + 1):
        for j in range(1, k + 1):
            a[i][j] = a[i - 1][j - 1] + a[i - 1][j]
    return a[n][k]