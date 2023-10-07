def damerau_levenshtein(a: str, b: str):
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
            if i > 1 and j > 1 and a[i - 2] == b[j - 1] and a[i - 1] == b[j - 2]:
                l[i][j] = min(l[i][j], l[i - 2][j - 2] + 1)
            if a[i - 1] == b[j - 1]:
                l[i][j] = l[i - 1][j - 1]
            else:
                l[i][j] = min(l[i][j], l[i - 1][j - 1] + 1)
    return l[n][m]


print(damerau_levenshtein('qtwtjg', 'gjdjw'))
print(damerau_levenshtein('gjdjhfdggndjmndfgaylh', 'fgksjkrylbhgjhj'))
print(damerau_levenshtein('', ''))
print(damerau_levenshtein('', 'fgksjkrylbhgjhj'))
print(damerau_levenshtein('gjdjhfdggndjmndfgaylh', ''))
print(damerau_levenshtein('aainforaticp', 'informatics'))
print(damerau_levenshtein('aainfor00aticp', 'informatics00'))
print(damerau_levenshtein('aainfor`0aticp', 'informatics+0'))
print(damerau_levenshtein('abcd', 'badc'))
print(damerau_levenshtein('abcd', 'badcutu'))
print(damerau_levenshtein('ab5cd', 'badcutu'))
