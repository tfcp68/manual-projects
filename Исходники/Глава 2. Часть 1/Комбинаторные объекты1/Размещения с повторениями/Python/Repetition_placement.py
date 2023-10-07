# k-длинна генерации, N количесто вариантов позициигенерации

from itertools import *

def RepetitionPlacement(k, N):

    result = 1
    for i in range(k):
        result *= N
    return result

def __shift(a:list, N):
    for i in reversed(range(len(a))):
        if a[i] >= N:
            a[i] = 0
            a[i-1] += 1
        else:
            break
    return a

def RepetitionPlacement_generation(k, N):

    per = RepetitionPlacement(k, N)
    a = []
    result = []
    for i in range(k):
        a.append(0)
    for i in range(per):
        result.append(a.copy())
        a[len(a)-1] += 1
        a = __shift(a, N)
    return result

def RepetitionPlacement_number(k, N, number):

    per = RepetitionPlacement(k, N)
    result = []
    for i in range(k):
        result.append(0)
    for i in range(k):
        plac = RepetitionPlacement(k - i - 1, N)
        result[i] = number // plac
        number = number % plac
    return result

def RepetitionPlacement_plac(k, N, placement: list):
    result = 0
    for i in range(len(placement)):
        plac = RepetitionPlacement(k - i - 1, N)
        result += plac * placement[i]
    return result


def RepetitionPlacement_plac_plus_1(k, N, placement: list):
    placement[len(placement) - 1] += 1
    result = __shift(placement, N)
    return result
