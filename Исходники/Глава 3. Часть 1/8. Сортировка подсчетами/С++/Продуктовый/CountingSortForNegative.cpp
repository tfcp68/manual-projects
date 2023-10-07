#include "CountSortForNegative.h"

#include <vector>
#include <iostream>
#include <algorithm>


std::vector<int> counting_sort_for_negative(std::vector<int> array) {

	int low = *std::min_element(array.begin(), array.end());
	int high = *std::max_element(array.begin(), array.end());

	std::vector<int> result(array.size(), 0);
	std::vector<int> count(high - low + 1, 0);

	for (int number : array) {
		count[number - low] += 1;
	}

	for (int index = 1; index < count.size(); index++) {
		count[index] += count[index - 1];
	}

	std::reverse(array.begin(), array.end());

	for (int number : array) {
		count[number - low] -= 1;
		result[count[number - low]] = number;
	}

	return result;
}


template <typename T>
std::vector<T> counting_sort_for_negative(std::vector<T> array) {

	int low = *std::min_element(array.begin(), array.end());
	int high = *std::max_element(array.begin(), array.end());

	std::vector<T> result(array.size(), 0);
	std::vector<int> count(high - low + 1, 0);

	for (T data : array) {
		count[data - low] += 1;
	}

	for (int index = 1; index < count.size(); index++) {
		count[index] += count[index - 1];
	}

	std::reverse(array.begin(), array.end());

	for (T data : array) {
		count[data - low] -= 1;
		result[count[data - low]] = data;
	}

	return result;
}



