def GetPermutationsAmount(n):
    s = [1] * n
    b = 2
    for i in range(1, n):
        s[i] = s[i - 1] * b
        b += 1
    if s != []:
        return s[-1]
    else:
        return 1


def GetNextPermutationInLexicographicOrder(permutation):
    n = len(permutation)

    # Находим наибольшее i, такое что a[i] < a[i+1]
    i = n - 2
    while i >= 0 and permutation[i] >= permutation[i + 1]:
        i -= 1

    if i == -1:
        # Если такого индекса нет, то мы перебрали все перестановки
        return []

    # Находим наибольшее j, такое что a[j] > a[i]
    j = n - 1
    while permutation[j] <= permutation[i]:
        j -= 1

    # Меняем местами числа a[i] и a[j]
    permutation[i], permutation[j] = permutation[j], permutation[i]

    # Разворачиваем суффикс a[i+1:]
    permutation[i + 1:] = permutation[i + 1:][::-1]

    return permutation


def GenerateAllPermutationsInLexicographicOrder(n):
    # Создаем список, содержащий первую перестановку в лексикографическом порядке
    current_perm = [i for i in range(1, n + 1)]
    permutations = [list(current_perm)]

    while True:
        # Находим наибольшее индекс i такое, что a[i] < a[i+1]
        i = n - 2
        while i >= 0 and current_perm[i] >= current_perm[i + 1]:
            i -= 1

        if i == -1:
            # Если такого индекса нет, то мы перебрали все перестановки
            break

        # Находим наибольшее j такое, что a[j] > a[i]
        j = n - 1
        while current_perm[j] <= current_perm[i]:
            j -= 1

        # Меняем местами числа a[i] и a[j]
        current_perm[i], current_perm[j] = current_perm[j], current_perm[i]

        # Разворачиваем суффикс a[i+1:]
        current_perm[i + 1:] = current_perm[i + 1:][::-1]

        # Добавляем новую перестановку в список
        permutations.append(list(current_perm))

    return permutations


def GetPermutationByPosition(position, n):  # position считается 0
    position -= 1
    if 0 <= position < GetPermutationsAmount(n):
        usedDigits = []
        result = ""

        for i in range(1, n + 1):
            sc = position // GetPermutationsAmount(n - i)
            position = position % GetPermutationsAmount(n - i)
            j = 1

            while (sc != 0) or (j in usedDigits):
                if not (j in usedDigits):
                    sc -= 1
                j += 1

            usedDigits.append(j)

            result += str(j)

        return int(result)
    else:
        return -1


def GetPositionByPermutation(n, permutation):
    usedDigits = []
    permutationIndex = 1
    p = [i + 1 for i in range(n)]

    if sorted(permutation) == p:
        for i in range(1, n + 1):
            j = 1
            digitsAmount = 0

            while j < permutation[i - 1]:
                if not (j in usedDigits):
                    digitsAmount += 1
                j += 1

            usedDigits.append(permutation[i - 1])
            permutationIndex += GetPermutationsAmount(n - i) * digitsAmount

        return permutationIndex

    else:
        return -1


print(GenerateAllPermutationsInLexicographicOrder(4))
