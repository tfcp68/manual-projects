def casino(cost, s, m, w):
    n = len(s)
    prefix_arr = [0] * n
    hyper_bool = [[[[False] * n for _ in range(m)] for _ in range(n)] for _ in range(n)]
    bool_ = [[False] * n for _ in range(n)]
    max_win = [[0] * n for _ in range(n)]

    prefix_arr[0] = cost[s[0]]
    for i in range(1, n):
        prefix_arr[i] = prefix_arr[i - 1] + cost[s[i]]

    # подготовка для вычисления bool
    for len_ in range(n):
        for i in range(n - len_):
            j = len_ + i
            for k in range(m):
                if len(w[k]) > n:
                    continue
                if i == j:
                    if s[i] == w[k][0]:
                        hyper_bool[i][j][k][0] = True
                    else:
                        hyper_bool[i][j][k][0] = False
                    continue

                for p in range(1, len(w[k])):

                    if s[j] != w[k][p]:
                        continue
                    for x in range(i, j):
                        if hyper_bool[i][x][k][p - 1] and (x == j - 1 or bool_[x + 1][j - 1]):
                            hyper_bool[i][j][k][p] = True

                if hyper_bool[i][j][k][len(w[k]) - 1]:
                    bool_[i][j] = True

            for k in range(i, j):
                if bool_[i][k] and bool_[k + 1][j]:
                    bool_[i][j] = True

    # вычисление подзадачи bool
    for len_ in range(n):
        for i in range(n - len_):
            j = i + len_
            for k in range(i + 1, j):
                if bool_[i][k] and bool_[k + 1][j]:
                    bool_[i][j] = True

    # вычисление подзадачи max_win
    for len_ in range(n):
        for i in range(n - len_):
            j = i + len_
            if bool_[i][j]:
                max_win[i][j] = prefix_arr[j] - prefix_arr[i - 1]
                continue
            for k in range(i, j):
                max_win[i][j] = max(max_win[i][j], max_win[i][k - 1] + max_win[k + 1][j])

    return max_win[0][n - 1]

cost = {'a': 1, 'b': 4, 'd': 2, 'x': 3, 'f': 1, 'e': 3}
s = 'fxeeabadd'
n = 2
w = ['aba', 'ed']

print(casino(cost, s, n, w))
