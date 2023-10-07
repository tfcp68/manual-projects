def fact(n):
    if n == 1:
        return 1
    answer = 1
    for i in range(2, n + 1):
        answer *= i
    return answer


def combinations(n, k):
    if n <= 0 or k <= 0 or k > n:
        return -1
    numer = fact(n)
    denom = fact(n - k) * fact(k)
    answer = numer // denom
    return answer

