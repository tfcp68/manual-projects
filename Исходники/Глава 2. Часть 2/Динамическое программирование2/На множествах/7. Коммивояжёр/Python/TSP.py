

def return_way(mask, last, p, cities):
    if not mask:
        return

    return_way(mask - (1 << last), p[mask][last], p, cities)
    cities.append(last + 1)
    return cities


def find_last_city(f, n, p):
    k = len_way = 0
    for i in range(1, n):
        if f[(1 << n) - 1][i] < f[(1 << n) - 1][k]:
            k = i
    len_way = f[(1 << n) - 1][k]
    way = return_way((1 << n) - 1, k, p, [])
    return len_way, way


def tsp(n, a):
    f = [[float('inf')] * n for _ in range(1 << n)]
    p = [[0] * n for _ in range(1 << n)]

    for mask in range(1, 1 << n):
        for k in range(0, n):
            if mask == (1 << k):
                f[mask][k] = 0

            if mask & (1 << k):
                pm = mask - (1 << k)

                for i in range(1, n):
                    if f[pm][i] + a[i][k] < f[mask][k]:
                        f[mask][k] = f[pm][i] + a[i][k]
                        p[mask][k] = i

    return find_last_city(f, n, p)




