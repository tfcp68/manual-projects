#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;


bool comp_fine(vi ord_1, vi ord_2) {
    return ord_1[1] > ord_2[1];
}


vvi init(vi deadlines, vi fines, int n) {
    vvi orders;
    for (int i = 0; i < n; i++) {
        vi order = { deadlines[i], fines[i], i + 1 };
        orders.push_back(order);
    }
    sort(orders.begin(), orders.end(), comp_fine);
    return orders;
}


bool comp_deadline(vi ord_1, vi ord_2) {
    return ord_1[0] < ord_2[0];
}


vi sort_order(vvi best_order) {
    vi begin;
    sort(best_order.begin(), best_order.end(), comp_deadline);
    for (vi order : best_order) {
        begin.push_back(order[2]);
    }
    return begin;
}


vi make_schedule(vi deadlines, vi fines, int n) {
    vi end, answer;
    vvi best_order;
    vvi orders = init(deadlines, fines, n);
    int num_order = 0;
    int end_time = *max_element(deadlines.begin(), deadlines.end()) + 1;
    for (int i = 0; i < end_time; i++) {
        if (num_order < n) {
            vi curr_order = orders[num_order];
            if (i <= curr_order[0]) {
                best_order.push_back(curr_order);
            }
            else {
                end.push_back(curr_order[2]);
            }
            num_order += 1;
        }
    }
    vi begin = sort_order(best_order);
    answer.insert(answer.begin(), begin.begin(), begin.end());
    answer.insert(answer.end(), end.begin(), end.end());
    return answer;
}