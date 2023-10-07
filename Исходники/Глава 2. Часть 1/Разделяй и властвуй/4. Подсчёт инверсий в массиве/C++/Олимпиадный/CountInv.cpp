#include <vector>
#include <iostream>


std::vector<std::vector<int>> split_array_inv(std::vector<int>& array) {
    std::vector<std::vector<int>> single_array;
    for (int i : array) {
        single_array.push_back({ i });
    }
    return single_array;
}


std::pair<std::vector<int>, int> sort_arrays_inv(std::vector<int>& array_1, std::vector<int>& array_2) {
    std::vector<int> first = array_1;
    std::vector<int> second = array_2;
    int i = 0;
    int j = 0;
    int cnt_inv = 0;
    std::vector<int> new_array;
    while (i < first.size() and j < second.size()) {
        if (first[i] < second[j]) {
            new_array.push_back(first[i]);
            i++;
        }
        else {
            new_array.push_back(second[j]);
            cnt_inv += (first.size() - i);
            j++;
        }
    }
    if (i < first.size() or j < second.size()) {
        new_array.insert(new_array.end(), first.begin() + i, first.end());
        new_array.insert(new_array.end(), second.begin() + j, second.end());
    }
    return std::make_pair(new_array, cnt_inv);
}


std::pair<std::vector<int>, int> merge_inv(std::vector<std::vector<int>>& array, int cnt) {
    std::vector<std::vector<int>> final_array;
    if (array.size() % 2 > 0) {
        array.push_back({});
    }
    for (int i = 0; i < array.size() - 1; i += 2) {
        std::pair<std::vector<int>, int> res = sort_arrays_inv(array[i], array[i + 1]);
        cnt += res.second;
        final_array.push_back(res.first);
    }
    if (final_array.size() == 1) {
        return std::make_pair(final_array[0], cnt);
    }
    return merge_inv(final_array, cnt);
}


int merge_sort_inv(std::vector<int>& array) {
    std::vector<std::vector<int>> single_array = split_array_inv(array);
    return merge_inv(single_array, 0).second;
}



