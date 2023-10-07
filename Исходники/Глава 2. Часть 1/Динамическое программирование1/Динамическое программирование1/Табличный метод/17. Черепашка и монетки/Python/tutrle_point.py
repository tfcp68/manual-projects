def turtle_point_forward(n, m, coins):
    if n <= 0 or m <= 0:
        return -1
    matrix = [[0 for _ in range(n)] for _ in range(m)]
    matrix[0][0] = coins[0][0]
    for j in range(m):
        for i in range(n):
            if i + 1 < n:
                matrix[j][i + 1] = max(matrix[j][i] + coins[j][i + 1], matrix[j][i + 1])
            if j + 1 < m:
                matrix[j + 1][i] = max(matrix[j][i] + coins[j + 1][i], matrix[j + 1][i])
    return matrix[m - 1][n - 1]


def turtle_point_back(n, m, coins):
    if n <= 0 or m <= 0:
        return -1
    matrix = [[0 for _ in range(n)] for _ in range(m)]
    matrix[0][0] = coins[0][0]
    for j in range(m):
        for i in range(n):
            if i == 0 and j == 0:
                continue
            if i != 0:
                matrix[j][i] = max(matrix[j][i - 1] + coins[j][i], matrix[j][i])
            if j != 0:
                matrix[j][i] = max(matrix[j - 1][i] + coins[j][i], matrix[j][i])
    return matrix[m - 1][n - 1]
