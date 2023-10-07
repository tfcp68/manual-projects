def petshop_array_back(n):
    if n < 0:
        return -1
    if n == 0:
        return 0
    if n < 3:
        return 2**(n)
    a = [0] * (n + 3)
    for i in range(3, n + 1):
        a[i] = a[i - 1] + 2 ** (i - 3)
    answer = 2 ** n - a[n]
    return answer

def petshop_array_forward(n):
    if n < 0:
        return -1
    if n == 0:
        return 0
    if n < 3:
        return 2**(n)
    a = [0] * (n + 3)
    for i in range(1, n):
        a[i + 2] = a[i + 1] + 2 ** (i - 1)
    answer = 2 ** n - a[n]
    return answer

#print(petshop_array_back(7))