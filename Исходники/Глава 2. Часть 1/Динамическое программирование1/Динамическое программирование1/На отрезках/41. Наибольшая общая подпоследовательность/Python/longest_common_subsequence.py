def longest_common_subsequence(a1: list, a2: list):
    n1 = len(a1)
    n2 = len(a2)
    if n1 == 0 or n2 == 0:
        return 0
    m = [[0] * (n2 + 1) for _ in range(n1 + 1)]
    for i in range(1, n1 + 1):
        for j in range(1, n2 + 1):
            if a1[i - 1] == a2[j - 1]:
                m[i][j] = m[i - 1][j - 1] + 1
            else:
                m[i][j] = max(m[i - 1][j], m[i][j - 1])
    return m[n1][n2]



