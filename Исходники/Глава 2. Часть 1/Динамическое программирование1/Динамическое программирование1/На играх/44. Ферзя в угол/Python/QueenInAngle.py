
def fill_table(dp, n, m):

    for i in range(m):
        dp[i][n - 1] = 1

    for j in range(n):
        dp[m - 1][j] = 1

    j = n - 1
    for i in range(m - 1, -1, -1):
        if j >= 0:
            dp[i][j] = 1
            j -= 1

    dp[m - 1][n - 1] = 0

    return dp


def winning_strategy(m, n, x, y):

    dp = [[0] * n for _ in range(m)]

    dp = fill_table(dp, n, m)

    for i in range(m - 2, -1, -1):
        for j in range(n - 2, -1, -1):
            if dp[i][j + 1] and dp[i + 1][j] and dp[i + 1][j + 1]:
                if not dp[i][j]:
                    dp = fill_table(dp, j + 1, i+1)

    if dp[y][x]:
        return 1
    return 2

