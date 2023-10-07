def fib_dp_forward(n):
    if n < 0:
        return -1
    arr = [0, 1] + [0] * n
    for i in range(0, n):
        arr[i + 1] += arr[i]
        arr[i + 2] += arr[i]
    return arr[n]