
import math


def distance(point1, point2):
    return ((point1[0] - point2[0])**2 + (point1[1] - point2[1])**2)**0.5


def find_best_points(points):
    best_points = ((math.inf, math.inf), (math.inf, math.inf))
    min_ = math.inf
    for p1 in range(len(points)):
        for p2 in range(len(points)):
            if p1 != p2:
                d = distance(points[p1], points[p2])
                if d < min_:
                    best_points = (points[p1], points[p2])
                    min_ = d
    return best_points


def middle_best_points(points_x, delta, lx):
    x_big = lx[len(lx)-1][0]
    middle_points = []
    for point in points_x:
        if (x_big - delta) <= point[0] <= (x_big + delta):
            middle_points.append(point)
    middle_points.sort(key=lambda point: point[1])
    best = delta
    best_pair = [(math.inf, math.inf), (math.inf, math.inf)]
    for i in range(len(middle_points)):
        for j in range(len(middle_points)):
            if middle_points[i] != middle_points[j]:
                if distance(middle_points[i], middle_points[j]) < best:
                    best = distance(middle_points[i], middle_points[j])
                    best_pair = [middle_points[i], middle_points[j]]
    return best_pair


def nearest_points(points_x, points_y):
    if len(points_x) <= 3:
        return find_best_points(points_x)

    lx = points_x[:len(points_x)//2]
    ly = points_y[:len(points_y)//2]

    rx = points_x[len(points_x)//2:]
    ry = points_y[len(points_y)//2:]

    l1, l2 = nearest_points(lx, ly)
    r1, r2 = nearest_points(rx, ry)

    delta = min(distance(l1, l2), distance(r1, r2))

    m1, m2 = middle_best_points(points_x, delta, lx)
    return min(find_best_points([l1, l2]), find_best_points([r1, r2]),
               find_best_points([m1, m2]),
               key=lambda point: distance(point[0], point[1]))




