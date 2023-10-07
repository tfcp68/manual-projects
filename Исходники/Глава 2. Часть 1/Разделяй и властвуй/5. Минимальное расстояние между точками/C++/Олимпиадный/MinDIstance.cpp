#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>


double distance(std::pair<double, double> point1, std::pair<double, double> point2) {
    if (point1.first == INFINITY or point2.first == INFINITY) {
        return INFINITY;
    }
    return std::sqrt(std::pow((point1.first - point2.first), 2) + std::pow((point1.second - point2.second), 2));
}


std::vector<std::pair<double, double>> find_best_points(std::vector<std::pair<double, double>> points) {
    std::vector<std::pair<double, double>> best_points = { std::make_pair(+INFINITY, +INFINITY), std::make_pair(+INFINITY, +INFINITY) };
    double min_ = +INFINITY;
    for (int p1 = 0; p1 < points.size(); p1++) {
        for (int p2 = 0; p2 < points.size(); p2++) {
            if (p1 != p2) {
                double d = distance(points[p1], points[p2]);
                if (d < min_) {
                    best_points = { points[p1], points[p2] };
                    min_ = d;
                }
            }
        }
    }
    return best_points;
}


bool compare_y(std::pair<double, double> point1, std::pair<double, double> point2) {
    return point1.second < point2.second;
}


bool compare_x(std::pair<double, double> point1, std::pair<double, double> point2) {
    return point1.first < point2.first;
}


std::vector<std::pair<double, double>> middle_best_points(std::vector<std::pair<double, double>> points_x, double delta,
                                                          std::vector<std::pair<double, double>> lx) {
    double x_big = lx[lx.size() - 1].first;
    std::vector<std::pair<double, double>> middle_points;
    for (std::pair<double, double> point : points_x) {
        if ((x_big - delta) <= point.first and point.first <= (x_big + delta)) {
            middle_points.push_back(point);
        }
    }
    std::sort(middle_points.begin(), middle_points.end(), compare_y);
    double best = delta;
    std::vector<std::pair<double, double>> best_pair = { std::make_pair(INFINITY, INFINITY), std::make_pair(INFINITY, INFINITY) };
    for (int i = 0; i < middle_points.size(); i++) {
        for (int j = 0; j < middle_points.size(); j++) {
            if (middle_points[i] != middle_points[j]) {
                if (distance(middle_points[i], middle_points[j]) < best) {
                    best = distance(middle_points[i], middle_points[j]);
                    best_pair = { middle_points[i], middle_points[j] };
                }
            }
        }
    }
    return best_pair;
}


std::vector<std::pair<double, double>> closest_pair(std::vector<std::pair<double, double>> points_x,
                                                    std::vector<std::pair<double, double>> points_y) {
    if (points_x.size() <= 3) {
        return find_best_points(points_x);
    }

    std::vector<std::pair<double, double>> lx, ly, rx, ry;
    
    lx.insert(lx.end(), points_x.begin(), points_x.end() - points_x.size() / 2);
    ly.insert(ly.end(), points_y.begin(), points_y.end() - points_y.size() / 2);
    rx.insert(rx.end(), points_x.begin() + points_x.size() / 2, points_x.end());
    ry.insert(ry.end(), points_y.begin() + points_y.size() / 2, points_y.end());
    std::vector<std::pair<double, double>> L = closest_pair(lx, ly);
    std::vector<std::pair<double, double>> R = closest_pair(rx, ry);

    std::pair<double, double> l1, l2, r1, r2, m1, m2;
    l1 = L[0]; l2 = L[1];
    r1 = R[0]; r2 = R[1];

    double delta = std::min(distance(l1, l2), distance(r1, r2));

    std::vector<std::pair<double, double>> M = middle_best_points(points_x, delta, lx);
    m1 = M[0], m2 = M[1];

    std::vector<std::pair<double, double>> pair_points_1 = find_best_points({ l1, l2 });
    std::vector<std::pair<double, double>> pair_points_2 = find_best_points({ r1, r2 });
    std::vector<std::pair<double, double>> pair_points_3 = find_best_points({ m1, m2 });

    double d1 = distance(pair_points_1[0], pair_points_1[1]);
    double d2 = distance(pair_points_2[0], pair_points_2[1]);
    double d3 = distance(pair_points_3[0], pair_points_3[1]);
    
    double min_distance = std::min(d3, std::min(d1, d2));

    if (min_distance == d1) {
        return pair_points_1;
    }
    else if (min_distance == d2) {
        return pair_points_2;
    }
    else {
        return pair_points_3;
    }
}


//int main() {
//    std::vector<std::pair<double, double>> points = { {1083.1394879892146, 83.4811446721369},{-974.2499208448369, -698.4087328365799},{-1220.5798641198135, -1158.7784373565119},{-1675.830803616027, 1318.7388096318036},{1857.1867444054942, -574.3678407445727},{-2586.79856803845, 2213.357161780673},{-2519.5680495172865, -609.2568545437093},{-294.643828574101, 2870.4978878501506},{-2749.839949009597, -59.62229766928658},{-2420.8094377387856, 2317.4181875807863},{1941.1740983802401, 2373.457713490012},{430.0307774112898, 2708.679518129996},{-1872.504638725291, -931.7741039020366},{-2464.312045576821, 1079.5950547324},{1243.2596883957503, 1192.166092859522} };
//    std::vector<std::pair<double, double>> points_x, points_y;
//
//    std::sort(points.begin(), points.end(), compare_x);
//    points_x.insert(points_x.begin(), points.begin(), points.end());
//
//    std::sort(points.begin(), points.end(), compare_y);
//    points_y.insert(points_y.begin(), points.begin(), points.end());
//
//    std::vector<std::pair<double, double>> a = find_best_points(points);
//    std::vector<std::pair<double, double>> b = closest_pair(points_x, points_y);
//    std::cout << distance(a[0], a[1]) << std::endl;
//    std::cout << distance(b[0], b[1]) << std::endl;
//    return 0;
//}