def palindrome_matrix(str_: str):
    n = len(str_)
    if n == 0:
        return 0
    p = [[0]*n for _ in range(n)]
    for i in range(n - 1, -1, -1):
        for j in range(n):
            if i >= j:
                p[i][j] = 0
            elif str_[i] == str_[j]:
                p[i][j] = p[i + 1][j - 1]
            else:
                p[i][j] = min(p[i + 1][j], p[i][j - 1]) + 1
    return p[0][n - 1]


def palindrome(str_: str):
    n = len(str_)
    if n == 0:
        return 0
    p = [[0] * n for _ in range(2)]
    for i in range(n - 1, -1, -1):
        for j in range(i + 1, n):
            if str_[i] == str_[j]:
                p[1][j] = p[0][j - 1]
            else:
                p[1][j] = 1 + min(p[0][j], p[1][j - 1])
        for j in range(0, n):
            p[0][j] = p[1][j]
            p[1][j] = 0
    return p[0][n - 1]



