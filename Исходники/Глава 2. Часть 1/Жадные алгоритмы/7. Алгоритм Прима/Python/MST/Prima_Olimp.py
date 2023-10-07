
edges = [(2, 5, 1), (4, 3, 5), (0, 1, 11), (2, 0, 7), (1, 3, 5), (4, 2, 2), (5, 3, 3)]
vtx = 6


def min_edge(visit, edges):
    arr = []
    for edge in edges:
        if edge[0] in visit or edge[1] in visit:
            if edge[0] not in visit or edge[1] not in visit:
                arr.append(edge)
    min_ = min(arr, key=lambda x: x[2])
    visit.add(min_[1])
    visit.add(min_[0])
    return min_


def prima(edges):
    mst = 0
    visit = {0}
    while len(visit) != vtx:
        mst += min_edge(visit, edges)[2]
    return mst


print(prima(edges))
