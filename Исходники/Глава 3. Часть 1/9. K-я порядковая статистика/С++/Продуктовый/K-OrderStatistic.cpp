#include <iostream>
#include <vector>


int k_order_statistic(std::vector<int>& array, int k) {

    if (array.size() == 1) {
        return array[0];
    }

    int pivot = array[array.size() / 2];
    std::vector<int> left, right, equal;

    for (int element : array) {

        if (element < pivot) {
            left.push_back(element);
        }

        else if (element > pivot) {
            right.push_back(element);
        }

        else {
            equal.push_back(element);
        }
    }

    if (k < left.size()) {
        return k_order_statistic(left, k);
    }

    else if (k < left.size() + equal.size()) {
        return equal[0];
    }

    else {
        return k_order_statistic(right, k - left.size() - equal.size());
    }
}


