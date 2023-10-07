def fib_formula(n):
    if n < 0:
        return -1
    root_five = sqrt(5)
    f = (1 + root_five)/2
    den = f**n - (- f)**(-n)
    num = 2 * f - 1
    fib = den / num
    return int(fib)