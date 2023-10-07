def binomial_theorem_linear_n(n, k):
    if n <= 0 or k <= 0 or k > n:
        return -1
    arr = [0] * (n + 1)
    arr[k] = 1
    for i in range(k + 1, n + 1):
        arr[i] = arr[i - 1] * i // (i - k)
    return arr[n]


def binomial_theorem_linear_k(n, k):
    if n <= 0 or k <= 0 or k > n:
        return -1
    arr = [0] * (k + 1)
    arr[0] = 1
    for i in range(1, k + 1):
        arr[i] = arr[i - 1] * (n - i + 1) // i
    return arr[k]
