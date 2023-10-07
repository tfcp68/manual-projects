from math import gcd


# Функция построения матрицы
def get_matrix(p, k):
    matrix = list()
    for i in range(len(p)):
        row = list()
        for j in range(len(p)):
            if (gcd(p[i], p[j]) >= k
                    and p[i] != p[j]):
                row.append(1)
                continue
            row.append(0)
        matrix.append(row)
    return matrix


def prepare(n, a):
    f = [[0] * n for _ in range(1 << n)]

    # Цикл по множествам
    for mask in range(1, 1 << n):

        # Цикл по элементам множества
        for i in range(n):

            # Если множество состоит из 1 элемента
            if mask == (1 << i):
                f[mask][i] = 1
                continue

            f[mask][i] = 0

            # Если элемент принадлежит множеству
            if mask & (1 << i):

                # Исключаем элемент - получаем подмножество меньшей мощности
                pm = mask - (1 << i)
                for j in range(0, n):

                    # Смотрим, какие элементы могут быть записаны после элемента i
                    if a[i][j]:
                        f[mask][i] += f[pm][j]
    return f


def find_permutation(n, m, k, p):

    # Сортируем перестановку - получаем минимальную в лексикографическом порядке
    p.sort()

    a = get_matrix(p, k)
    f = prepare(n, a)
    total = prev = 0

    # Вычисление общего количества перестановок
    for i in range(0, n):
        total += f[(1 << n) - 1][i]

    # Если перестановок меньше чем m, то выводим -1
    if m > total:
        return '-1'

    # Исходное множество
    mask = (1 << n) - 1

    res = str()

    # Цикл по шагам
    for step in range(1, n + 1):

        # Цикл по элементам множества
        for i in range(0, n):

            # Если элемент принадлежит множеству
            if mask & (1 << i):

                # Если элемент не может находиться на этом месте в перестановке, то продолжаем поиск
                if step > 1 and (not a[prev][i]):
                    continue

                # Ищем m-ую перестановку
                if m > f[mask][i]:
                    m -= f[mask][i]

                # Найдем элемент, который находится на месте step в перестановке
                else:
                    prev = i
                    res += str(p[i]) + " "

                    # Изменяем множество
                    mask -= (1 << i)
                    break
    return res


print(find_permutation(4, 5, 2, [6, 8, 3, 9]))
