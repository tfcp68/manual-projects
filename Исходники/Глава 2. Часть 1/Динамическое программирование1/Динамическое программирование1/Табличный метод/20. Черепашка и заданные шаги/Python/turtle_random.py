def turtle_random_forward(n, m, coins, steps):
    if n <= 0 or m <= 0:
        return -1
    matrix = [[0 for _ in range(n)] for _ in range(m)]
    matrix[0][0] = coins[0][0]
    for j in range(m):
        for i in range(n):
            for z in steps:
                if z > n - i - 1 or z == 0:
                    continue
                matrix[j][i + z] = max(matrix[j][i] + coins[j][i + z], matrix[j][i + z])
            for z in steps:
                if z > m - j - 1 or z == 0:
                    continue
                matrix[j + z][i] = max(matrix[j][i] + coins[j + z][i], matrix[j + z][i])
    return matrix[m - 1][n - 1]


def turtle_random_back(n, m, coins, steps):
    if n <= 0 or m <= 0:
        return -1
    matrix = [[0 for _ in range(n)] for _ in range(m)]
    matrix[0][0] = coins[0][0]
    for j in range(m):
        for i in range(n):
            if i == 0 and j == 0:
                continue
            for z in steps:
                if z > i or z == 0:
                    continue
                matrix[j][i] = max(matrix[j][i - z] + coins[j][i], matrix[j][i])
            for z in steps:
                if z > j or z == 0:
                    continue
                matrix[j][i] = max(matrix[j - z][i] + coins[j][i], matrix[j][i])
    return matrix[m - 1][n - 1]
