def sum_decomp(n):
    if n <= 0:
        return -1
    sums = [0] * (n + 1)
    sums[0] = 1
    for i in range(1, n):
        for j in range(i, n + 1):
            sums[j] += sums[j - i]
    return sums[n]

def sum_matrix(n):
    k = n - 1
    if n <= 0:
        return -1
    sums = [[0 for _ in range(n + 1)] for _ in range(n + 1)]
    for k in range(1, n + 1):
        sums[0][k] = 1
    for i in range(1, n + 1):
        for k in range(1, i + 1):
            sums[i][k] = sums[i][k - 1] + sums[i - k][k]
        for k in range(i + 1, n + 1):
            sums[i][k] = sums[i][k - 1]
    return sums[n][k] - 1

print(sum_matrix(100))

