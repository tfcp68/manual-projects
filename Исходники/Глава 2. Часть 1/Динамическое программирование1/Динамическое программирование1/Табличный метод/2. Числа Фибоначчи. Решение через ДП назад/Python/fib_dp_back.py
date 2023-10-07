def fib_dp_back(n):
    if n < 0:
        return -1
    arr = [0, 1]
    for i in range(2, n + 1):
        q = arr[i - 1] + arr[i - 2]
        arr.append(q)
    return arr[n]