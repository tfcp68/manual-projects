# Есть рюкзак с вместимостью не более, чем W грамм (W - целое)
# и N предметов весом wi грамм и стоимостью ci за грамм.
# Мы умеем отрезать от любого предмета целое количество грамм.
# Требуется набрать рюкзак максимальной стоимости.


N = 6
W = 15
c = [5, 8, 1, 2, 3, 5]
w = [4, 9, 6, 7, 1, 2]


def backpack(W, N, c, w):
    items = list()
    for i in range(N):
        items.append((c[i], w[i]))

    items = sorted(items, key=lambda x: x[0]/x[1], reverse=True)

    res = 0
    for i in range(N):
        res += min(items[i][1], W) * items[i][0]
        W -= min(items[i][1], W)
    return res


# print(backpack(W, N, c, w))
