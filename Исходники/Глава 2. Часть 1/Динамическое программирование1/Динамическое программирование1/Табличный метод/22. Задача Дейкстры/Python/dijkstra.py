def dijkstra_back(n):
    if n <= 0:
        return -1
    arr = [0] * (n + 1)
    arr[1] = 1
    for i in range(2, n + 1):
        if i % 2 == 0:
            arr[i] = arr[i//2]
        else:
            arr[i] = arr[(i - 1)//2] + arr[(i - 1)//2 + 1]
    return arr[n]


def dijkstra_forward(n):
    if n <= 0:
        return -1
    arr = [0] * (2 * n + 1)
    arr[1] = 1
    for i in range(1, n):
        arr[2 * i] = arr[i]
        arr[2 * i + 1] = arr[i] + arr[i+1]
    return arr[n]


def dijkstra_book(n):
    if n < 0:
        return -1
    arr = [0] * (2 * n + 1)
    arr[1] = 1
    for i in range(1, n):
        arr[2 * i] = arr[i]
        arr[2 * i + 1] = arr[i] + arr[i+1]
    return arr[n]


