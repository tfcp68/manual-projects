def petshop_matrix_back(n):
    if n < 0:
        return -1
    a = [[0 for i in range(n)] for j in range(n)]
    for i in range(n):
        for j in range(i, n):
            if j == 0 and i == 0:
                a[i][j] = 1
            elif i == 0:
                a[i][j] = 2 ** (j - 1)
            else:
                a[i][j] = a[i - 1][j - 1]
    sum_3 = 0
    for i in range(2, n):
        for j in range(i, n):
            sum_3 += a[i][j]
    answer = 2**n - sum_3
    if n == 0:
        answer = 0
    return answer

def petshop_matrix_forward(n):
    if n < 0:
        return -1
    a = [[0 for i in range(n + 1)] for j in range(n + 1)]
    for i in range(n):
        for j in range(i, n):
            if j == 0 and i == 0:
                a[i][j] = 1
            elif i == 0:
                a[i][j] = 2 ** (j - 1)
            a[i + 1][j + 1] = a[i][j]
    sum_3 = 0
    for i in range(2, n):
        for j in range(i, n):
            sum_3 += a[i][j]
    answer = 2**n - sum_3
    if n == 0:
        answer = 0
    return answer