#include <vector>
#include <iostream>
#include <ctime>


std::vector<std::vector<int>> split_array(std::vector<int> &array) {
    std::vector<std::vector<int>> single_array;
    for (int i : array) {
        single_array.push_back({ i });
    }
    return single_array;
}


std::vector<int> sort_arrays(std::vector<int> &array_1, std::vector<int> &array_2) {
    std::vector<int> first = array_1;
    std::vector<int> second = array_2;
    int i = 0;
    int j = 0;
    std::vector<int> new_array;
    while (i < first.size() and j < second.size()) {
        if (first[i] < second[j]) {
            new_array.push_back(first[i]);
            i++;
        }
        else {
            new_array.push_back(second[j]);
            j++;
        }
    }
    if (i < first.size() or j < second.size()) {
        new_array.insert(new_array.end(), first.begin() + i, first.end());
        new_array.insert(new_array.end(), second.begin() + j, second.end());
    }
    return new_array;
}


std::vector<int> merge(std::vector<std::vector<int>> &array) {
    std::vector<std::vector<int>> final_array;
    if (array.size() % 2 > 0) {
        array.push_back({});
    }
    for (int i = 0; i < array.size() - 1; i += 2) {
        std::vector<int> curr = sort_arrays(array[i], array[i + 1]);
        final_array.push_back(curr);
    }
    if (final_array.size() == 1) {
        return final_array[0];
    }
    return merge(final_array);
}


std::vector<int> merge_sort(std::vector<int>& array) {
    std::vector<std::vector<int>> single_array = split_array(array);
    return merge(single_array);
}


