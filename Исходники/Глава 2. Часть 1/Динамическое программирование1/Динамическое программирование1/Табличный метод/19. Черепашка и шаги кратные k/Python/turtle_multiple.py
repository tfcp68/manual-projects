def turtle_multiple_forward(n, m, coins, k):
    if n <= 0 or m <= 0:
        return -1
    matrix = [[0 for _ in range(n)] for _ in range(m)]
    matrix[0][0] = coins[0][0]
    for j in range(m):
        for i in range(n):
            for z in range(1, (n - i) // k + 1):
                if i + z * k < n:
                    matrix[j][i + z * k] = max(matrix[j][i] + coins[j][i + z * k], matrix[j][i + z * k])
            for z in range(1, (m - j) // k + 1):
                if j + z * k < m:
                    matrix[j + z * k][i] = max(matrix[j][i] + coins[j + z * k][i], matrix[j + z * k][i])
    return matrix[m - 1][n - 1]


def turtle_multiple_back(n, m, coins, k):
    if n <= 0 or m <= 0:
        return -1
    matrix = [[0 for _ in range(n)] for _ in range(m)]
    matrix[0][0] = coins[0][0]
    for j in range(m):
        for i in range(n):
            if i == 0 and j == 0:
                continue
            for z in range(1, i // k + 1):
                if i != 0:
                    matrix[j][i] = max(matrix[j][i - z * k] + coins[j][i], matrix[j][i])
            for z in range(1, j // k + 1):
                if j != 0:
                    matrix[j][i] = max(matrix[j - z * k][i] + coins[j][i], matrix[j][i])
    return matrix[m - 1][n - 1]
