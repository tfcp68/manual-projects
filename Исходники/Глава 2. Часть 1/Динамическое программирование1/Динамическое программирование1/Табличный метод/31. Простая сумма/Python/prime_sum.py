def prime_sum(n):
    if n <= 0:
        return -1
    if n == 1:
        return 4
    primes = [2, 3, 5, 7, 11, 13, 17]
    matrix_sum = [[0 for _ in range(10)] for _ in range(n)]
    prime_bool = [False] * 19
    for i in primes:
        prime_bool[i] = True
    for i in range(1, 10):
        matrix_sum[0][i] = 1
    for j in range(1, n):
        for i in range(10):
            matrix_sum[j][i] = 0
            for k in range(10):
                if prime_bool[k + i]:
                    matrix_sum[j][i] += matrix_sum[j - 1][k]
    answer = 0
    for i in range(10):
        answer += matrix_sum[n - 1][i]
    return answer
