def match_game(n, k):
    bool_ = [[False] * (n + 1) for _ in range(n + 1)]
    for j in range(1, n + 1):
        bool_[0][j] = True
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            m = j + 1
            if m >= i:
                m = i - 1
            for t in range(1, m + 1):
                bool_[i][j] = bool_[i][j] or (not bool_[i-t][t])

    m = k
    if m > n:
        m = n
    answer = []
    for t in range(1, m + 1):
        if not bool_[n - t][t]:
            answer += [t]

    return answer



print(match_game(5, 3))
