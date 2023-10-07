def turtle_forward(n, m):
    if n <= 0 or m <= 0:
        return -1
    matrix = [[0 for _ in range(n)] for _ in range(m)]
    matrix[0][0] = 1
    for j in range(m):
        for i in range(n):
            if i + 1 < n:
                matrix[j][i + 1] += matrix[j][i]
            if j + 1 < m:
                matrix[j + 1][i] += matrix[j][i]
    return matrix[m - 1][n - 1]


def turtle_back(n, m):
    if n <= 0 or m <= 0:
        return -1
    matrix = [[0 for _ in range(n)] for _ in range(m)]
    matrix[0][0] = 1
    for j in range(m):
        for i in range(n):
            if i == 0 and j == 0:
                continue
            if i != 0:
                matrix[j][i] += matrix[j][i - 1]
            if j != 0:
                matrix[j][i] += matrix[j - 1][i]
    return matrix[m - 1][n - 1]
