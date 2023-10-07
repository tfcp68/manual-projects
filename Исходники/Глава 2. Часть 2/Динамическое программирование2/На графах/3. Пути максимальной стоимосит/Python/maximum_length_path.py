from math import inf


def maximum_length_path(graph, v, start):
    dist = [-inf] * v
    dist[start] = 0

    for _ in range(v - 1):
        was_updated = False
        for i in graph:
            for j in graph[i]:
                if dist[i] + 1 > dist[j]:
                    dist[j] = dist[i] + 1
                    was_updated = True
        if not was_updated:
            break

    for i in graph:
        for j, w in graph[i]:
            if dist[j] < dist[i] + 1:
                return False, dist

    return True, dist
