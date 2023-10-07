def GetPlacementsCount(n: int, m: int):  # 1 done
    result = 1

    for i in range(0, m):
        result *= (n - i)

    return result


def GetPlacementsInLexicographicOrder(n: int, m: int):  # 2 done
    elements = []
    usedDigits = []
    result = []

    def Solve(index: int):
        for i in range(1, n + 1):
            if (not (i in usedDigits)):
                usedDigits.append(i)
                elements.append(i)

                if index < m:
                    Solve(index + 1)

                else:
                    result.append(tuple(usedDigits.copy()))

                usedDigits.remove(i)

    Solve(1)
    return result


def GetNextPlacementInLexicographicOrder(n: int, m: int, placement: list):  # 3 done
    # a = [False] + [i for i in range(1, m + 1)]
    a = [False] + placement
    free = [False for i in range(0, n + 1)]

    def FreeNext(t: int):
        while (t <= n) and (not (free[t])):
            t += 1

        if t > n:
            return 0
        else:
            return t

    for i in range(1, n + 1):
        free[i] = True

    for i in range(1, m + 1):
        free[a[i]] = False

    i = m

    while (i > 0) and (FreeNext(a[i]) == 0):
        free[a[i]] = True
        i -= 1

    free[a[i]] = True

    q = FreeNext(a[i] + 1)
    free[q] = False
    a[i] = q
    k = 1

    for j in range(i + 1, m + 1):
        while (k <= m) and not (free[k]):
            if k >= n:
                k = 1
            else:
                k += 1
        a[j] = k
        free[k] = False

    return a[1:]


def GetPlacementByIndex(n: int, m: int, l: int):  # 4 done

    number = []

    def Solve(l: int):
        free = [False for i in range(0, n + 2)]

        for i in range(1, n + 1):
            free[i] = i

        for i in range(1, m + 1):
            t = GetPlacementsCount(n - i, m - i)
            q = l // t
            number.append(free[q + 1])

            for j in range(q + 1, (n - i) + 1):
                free[j] = free[j + 1]

            l = l % t

    Solve(l)
    return tuple(number)


def GetIndexByPlacement(n: int, m: int, placement: list):  # 5
    a = [False] + placement
    unUsedNumbers = []
    l = 0

    for i in range(1, m + 1):
        unBusyElements = 0

        for j in range(1, a[i]):
            if not (j in unUsedNumbers):
                unBusyElements += 1

        unUsedNumbers.append(a[i])

        l += unBusyElements * GetPlacementsCount(n - i, m - i)

    return l
