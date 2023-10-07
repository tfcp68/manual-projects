def damerau_levenshtein_count(a: str, b: str):
    alpha = list(map(chr, range(97, 123)))
    n = len(a)
    m = len(b)
    l = [[0]*(m + 1) for _ in range(n + 1)]
    for i in range(1, n + 1):
        l[i][0] = alpha.index(a[i - 1]) + l[i - 1][0] + 1
    for j in range(1, m + 1):
        l[0][j] = alpha.index(b[j - 1]) + l[0][j - 1] + 1
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            ind_i = alpha.index(a[i - 1]) + 1
            ind_j = alpha.index(b[j - 1]) + 1
            l[i][j] = min(l[i - 1][j] + ind_i, l[i][j - 1] + ind_j)
            if i > 1 and j > 1 and a[i - 2] == b[j - 1] and a[i - 1] == b[j - 2]:
                count = l[i - 1][j - 1]
                l[i][j] = min(l[i][j], count + 1)
            if a[i - 1] == b[j - 1]:
                l[i][j] = l[i - 1][j - 1]
            else:
                count = l[i - 1][j - 1]
                l[i][j] = min(l[i][j], count + abs(ind_j - ind_i))
    return l[n][m]


print(damerau_levenshtein_count('qtwtjg', 'gjdjw'))
print(damerau_levenshtein_count('gjdjhfdggndjmndfgaylh', 'fgksjkrylbhgjhj'))
print(damerau_levenshtein_count('', ''))
print(damerau_levenshtein_count('', 'fgksjkrylbhgjhj'))
print(damerau_levenshtein_count('gjdjhfdggndjmndfgaylh', ''))
print(damerau_levenshtein_count('aainforaticp', 'informatics'))
print(damerau_levenshtein_count('abcd', 'badc'))
print(damerau_levenshtein_count('abcd', 'badcutu'))
print(damerau_levenshtein_count('abrcd', 'badcutu'))
