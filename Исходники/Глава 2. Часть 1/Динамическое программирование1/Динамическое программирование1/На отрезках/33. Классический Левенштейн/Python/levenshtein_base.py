def levenshtein_base(a: str, b: str):
    n = len(a)
    m = len(b)
    l = [[0]*(m + 1) for _ in range(n + 1)]
    for i in range(n + 1):
        l[i][0] = i
    for j in range(m + 1):
        l[0][j] = j
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            l[i][j] = min(l[i - 1][j], l[i][j - 1]) + 1
            if a[i - 1] == b[j - 1]:
                l[i][j] = l[i - 1][j - 1]
            else:
                l[i][j] = min(l[i][j], l[i - 1][j - 1] + 1)
    return l[n][m]


print(levenshtein_base('qtwtjg', 'gjdjw'))
print(levenshtein_base('gjdjhfdggndjmndfgaylh', 'fgksjkrylbhgjhj'))
print(levenshtein_base('', ''))
print(levenshtein_base('', 'fgksjkrylbhgjhj'))
print(levenshtein_base('gjdjhfdggndjmndfgaylh', ''))
print(levenshtein_base('aainforaticp', 'informatics'))
print(levenshtein_base('aainfor00aticp', 'informatics00'))
print(levenshtein_base('aainfor`0aticp', 'informatics+0'))
