def turtle_and_k_step_forward(n, m, coins, k):
    if n <= 0 or m <= 0:
        return -1
    matrix = [[0 for _ in range(n)] for _ in range(m)]
    matrix[0][0] = coins[0][0]
    for j in range(m):
        for i in range(n):
            r = min(k, n - i - 1)
            for z in range(1, r + 1):
                if i + 1 < n:
                    matrix[j][i + z] = max(matrix[j][i] + coins[j][i + z], matrix[j][i + z])
            r = min(k, m - j - 1)
            for z in range(1, r + 1):
                if j + 1 < m:
                    matrix[j + z][i] = max(matrix[j][i] + coins[j + z][i], matrix[j + z][i])
    return matrix[m - 1][n - 1]


def turtle_and_k_step_back(n, m, coins, k):
    if n <= 0 or m <= 0:
        return -1
    matrix = [[0 for _ in range(n)] for _ in range(m)]
    matrix[0][0] = coins[0][0]
    for j in range(m):
        for i in range(n):
            if i == 0 and j == 0:
                continue
            r = min(k, i)
            for z in range(1, r + 1):
                if i != 0:
                    matrix[j][i] = max(matrix[j][i - z] + coins[j][i], matrix[j][i])
            r = min(k, j)
            for z in range(1, r + 1):
                if j != 0:
                    matrix[j][i] = max(matrix[j - z][i] + coins[j][i], matrix[j][i])
    return matrix[m - 1][n - 1]
