#include <vector>
#include <iostream>

template <typename T>
int bin_search(std::vector<T> array, T data) {
	int begin = 0;
	int end = array.size() - 1;
	while (begin <= end) {
		int middle = (begin + end) / 2;
		T guess = array[middle];
		if (guess == data) {
			return middle;
		}
		if (guess < data) {
			begin = middle + 1;
		}
		else {
			end = middle - 1;
		}
	}
	return -1;
}


int bin_search_olympic(std::vector<int> arr, int i) {
	int begin = 0;
	int end = arr.size() - 1;
	while (begin <= end) {
		int mid = (begin + end) / 2;
		if (arr[mid] == i) {
			return mid;
		}
		if (arr[mid] < i) {
			begin = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	return -1;
}

