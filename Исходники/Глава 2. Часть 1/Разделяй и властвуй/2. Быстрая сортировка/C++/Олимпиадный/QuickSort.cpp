#include <vector>
#include <iostream>
#include <algorithm>


template <typename T>
int partition(std::vector<T> &array, int begin, int end) {
    T pivot = array[(begin + end) / 2];
    int i = begin;
    int j = end;
    while (true) {
        while (array[i] < pivot) {
            i++;
        }
        while (array[j] > pivot) {
            j--;
        }
        if (i >= j) {
            return j;
        }
        std::swap(array[i++], array[j--]);
    }
}


template <typename T>
void quick_sort(std::vector<T> &array, int begin, int end) {
    if (begin < end) {
        int pivot_index = partition(array, begin, end);
        quick_sort(array, begin, pivot_index);
        quick_sort(array, pivot_index + 1, end);
    }
    return;
}
    

