def fib_ec_mem(n, a = 0, b = 1):
    if n < 0:
        return -1
    if n == 0:
        return a
    else:
        return fib_ec_mem(n - 1, b, a + b)