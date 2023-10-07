def fib_recursion(n):
    if n < 0:
        return -1
    if n == 0:
        return 0
    if n == 1 or n == 2:
        return 1
    return fib_recursion(n - 1) + fib_recursion(n - 2)
