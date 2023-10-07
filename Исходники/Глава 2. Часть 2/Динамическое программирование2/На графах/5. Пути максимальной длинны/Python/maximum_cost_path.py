from math import inf


def bellman_ford_maximum(graph, v, start):
    dist = [-inf] * v
    dist[start] = 0

    for _ in range(v - 1):
        was_updated = False
        for i in graph:
            for j, w in graph[i]:
                if dist[i] + w > dist[j]:
                    dist[j] = dist[i] + w
                    was_updated = True
        if not was_updated:
            break

    for i in graph:
        for j, w in graph[i]:
            if dist[j] < dist[i] + w:
                return False, dist

    return True, dist
