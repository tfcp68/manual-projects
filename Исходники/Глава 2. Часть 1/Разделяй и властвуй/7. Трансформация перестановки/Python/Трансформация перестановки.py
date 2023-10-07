import math
from collections import deque


def build_tree(arr: list, tree):
    root = max(arr)
    index_root = arr.index(root)
    arr.remove(root)

    left = arr[:index_root]
    right = arr[index_root:]

    if len(left) > 0:
        tree[root].append(max(left))
        build_tree(left, tree)

    if len(right) > 0:
        tree[root].append(max(right))
        build_tree(right, tree)

    return tree


def bfs(graph, start):
    deeps = [math.inf] * (len(graph) + 1)
    deeps[start] = 0
    queue = deque()
    queue.append(start)

    while queue:
        node = queue.popleft()
        for i in graph[node]:
            if deeps[i] > deeps[node] + 1:
                deeps[i] = deeps[node] + 1
                queue.append(i)

    return deeps


def solve():
    n = int(input())

    arr = list(map(int, input().split()))

    start = max(arr)

    tree = {}
    for i in arr:
        tree[i] = []

    build_tree(arr, tree)
    deeps = bfs(tree, start)

    for i in tree:
        print(deeps[i], end=' ')
    print()
    return


def main():
    t = int(input())
    for _ in range(t):
        solve()


main()

