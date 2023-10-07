from math import inf
import heapq


def dijkstra(graph, start):
    dist = [inf] * len(graph)
    dist[start] = 0

    visited = [False] * len(graph)

    for _ in range(len(graph)):
        min_dist = inf
        min_index = -1

        for i in range(len(graph)):
            if not visited[i] and dist[i] < min_dist:
                min_dist = dist[i]
                min_index = i

        if min_index == -1:
            break

        visited[min_index] = True

        for i in range(len(graph)):
            if graph[min_index][i] != 0 and not visited[i]:
                dist[i] = min(dist[i], dist[min_index] + graph[min_index][i])

    return dist


def heap_dijkstra(graph, start):
    distances = [inf] * len(graph)
    distances[start] = 0

    visited = [False] * len(graph)

    heap = [(0, start)]

    while heap:
        min_distance, min_index = heapq.heappop(heap)

        if visited[min_index]:
            continue

        visited[min_index] = True

        for i in range(len(graph)):
            if graph[min_index][i] != 0 and not visited[i]:
                distances[i] = min(
                    distances[i], distances[min_index] + graph[min_index][i])
                heapq.heappush(heap, (distances[i], i))

    return distances