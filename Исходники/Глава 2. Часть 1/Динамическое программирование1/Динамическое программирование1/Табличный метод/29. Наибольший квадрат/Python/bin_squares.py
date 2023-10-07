def biggest_square(a: list, n: int, m: int):
    b = [[0 for _ in range(n)] for _ in range(m)]
    for i in range(n):
        b[0][i] = a[0][i]
    for j in range(m):
        b[j][0] = a[j][0]
    for j in range(1, m):
        for i in range(1, n):
            if a[j][i] == 0:
                b[j][i] = a[j][i]
            else:
                b[j][i] = min(b[j - 1][i], b[j - 1][i - 1], b[j][i - 1]) + 1
    max_square = 0
    for j in range(m):
        for i in range(n):
            if b[j][i] > max_square:
                max_square = b[j][i]
    return max_square

def bad_biggest_square(a: list, n: int, m: int):
    b = [[0 for _ in range(n)] for _ in range(m)]
    for i in range(n):
        b[m - 1][i] = a[m - 1][i]
    for j in range(m):
        b[j][n - 1] = a[j][n - 1]
    for j in range(m - 2, -1, -1):
        for i in range(n - 2, -1, -1):
            if a[j][i] == 0:
                b[j][i] = a[j][i]
            else:
                b[j][i] = min(b[j + 1][i], b[j + 1][i + 1], b[j][i + 1]) + 1
    max_square = 0
    for j in range(m):
        for i in range(n):
            if b[j][i] > max_square:
                max_square = b[j][i]
    return max_square

a = [[0, 0, 0, 0, 0], [0, 1, 1, 1, 1], [1, 1, 1, 1, 1], [1, 1, 1, 1, 1], [0, 1, 1, 1, 1], [1, 0, 1, 1, 1]]
a1 = [[0, 0, 1, 1, 0, 1], [0, 1, 1, 1, 1, 0], [0, 1, 1, 1, 1, 1], [0, 1, 1, 1, 1, 1], [0, 1, 1, 1, 1, 1]]
a2 = [[1, 0, 1, 1, 1, 1, 1], [0, 0, 1, 1, 1, 1, 1], [1, 1, 1, 1, 1, 1, 1], [1, 1, 1, 1, 1, 1, 1], [1, 1, 1, 1, 1, 1, 1]]
a3 = [[0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0]]
print(biggest_square(a3, 7, 5))
print(bad_biggest_square(a2, 7, 5))