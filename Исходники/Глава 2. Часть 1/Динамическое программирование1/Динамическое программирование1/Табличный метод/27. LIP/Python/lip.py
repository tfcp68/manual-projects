def lip_forward(a):
    if len(a) == 1:
        return 1
    if len(a) == 0:
        return 0
    count_a = [1] * len(a)
    for i in range(len(a) - 1, -1, -1):
        for j in range(len(a) - 1, i, -1):
            if a[j] > a[i] and count_a[j] + 1 > count_a[i]:
                count_a[i] = count_a[j] + 1
    count_a.sort()
    return count_a[-1]


def lip_back(a):
    if len(a) == 1:
        return 1
    if len(a) == 0:
        return 0
    count_a = [1] * len(a)
    for i in range(len(a)):
        for j in range(0, i):
            if a[j] < a[i] and count_a[j] + 1 > count_a[i]:
                count_a[i] = count_a[j] + 1
    count_a.sort()
    return count_a[-1]
a = [4, 1, 7, 5, 2, 5, 8, 3]
print(lip_forward(a))