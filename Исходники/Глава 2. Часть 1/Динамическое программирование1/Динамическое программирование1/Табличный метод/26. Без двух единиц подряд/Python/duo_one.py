def duo_one(n):
    if n <= 0:
        return -1
    a = [0] * (n + 1)
    a[0] = 1
    a[1] = 2
    for i in range(2, n + 1):
        a[i] = a[i - 1] + a[i - 2]
    return a[n]

print(duo_one(2))