A = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
n = len(A)
F = []
for i in range(0, n):
    F.append(0)

def modify(index, delta):
    while index < n:
        F[index] += delta;
        index = index | (index + 1)


def temp_sum(index):
    res = 0
    while index >= 0:
        res += F[index]
        index = (index & (index + 1)) - 1

    return res


def sum(l, r):
    sum1 = temp_sum(r)
    sum2 = temp_sum(l - 1)
    res = sum1 - sum2
    return res

def build():
    for i in range(0, n):
        modify(i, A[i])



build()
for i in range(0, n):
    for j in range(i, n):
        print(sum(i, j), end=" ")
    print("\n")






