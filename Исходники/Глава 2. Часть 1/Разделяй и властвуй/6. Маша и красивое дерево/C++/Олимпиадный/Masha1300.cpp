#include <vector>
#include <iostream>
#include <algorithm>

std::vector<std::vector<int>> split_array(std::vector<int> array) {
    if (array.size() <= 2) {
        return { array };
    }
    std::vector<std::vector<int>> result;
    for (int i = 0; i < array.size() - 1; i += 2) {
        result.push_back({ array[i], array[i + 1] });
    }
    return result;
}

std::pair<std::vector<int>, int> sort_array(std::vector<std::vector<int>> array, int count) {
    if (array.size() <= 1) {
        return { array[0], count };
    }
    std::vector<std::vector<int>> new_array;
    for (int i = 0; i < array.size() - 1; i += 2) {
        if (array[i][0] > array[i + 1][0]) {
            std::vector<int> merge_array;
            merge_array.insert(merge_array.end(), array[i + 1].begin(), array[i + 1].end());
            merge_array.insert(merge_array.end(), array[i].begin(), array[i].end());
            new_array.push_back(merge_array);
            count++;
        }
        else {
            std::vector<int> merge_array;
            merge_array.insert(merge_array.end(), array[i].begin(), array[i].end());
            merge_array.insert(merge_array.end(), array[i + 1].begin(), array[i + 1].end());
            new_array.push_back(merge_array);
        }
    }
    return sort_array(new_array, count);
}


void solve() {
    int len_array;
    std::cin >> len_array;
    std::vector<int> array;
    std::vector<int> array_sort;
    for (int i = 0; i < len_array; i++) {
        int digit;
        std::cin >> digit;
        array.push_back(digit);
        array_sort.push_back(digit);
    }
    std::sort(array_sort.begin(), array_sort.end());
    if (array == array_sort) {
        std::cout << 0 << std::endl;
        return;
    }

    std::vector<std::vector<int>> new_array;
    new_array = split_array(array);

    int count = 0;
    for (int i = 0; i < new_array.size(); i++) {
        if (new_array[i][0] > new_array[i][1]) {
            new_array[i] = { new_array[i][1], new_array[i][0] };
            count++;
        }
    }
    std::vector<int> result, sort_result;
    std::pair<std::vector<int>, int> 
        final_array_and_count = sort_array(new_array, count);
    result = final_array_and_count.first;
    sort_result = final_array_and_count.first;
    count = final_array_and_count.second;

    std::sort(sort_result.begin(), sort_result.end());

    if (result == sort_result) {
        std::cout << count << std::endl;
    }
    else {
        std::cout << -1 << std::endl;
    }
    return;
}

