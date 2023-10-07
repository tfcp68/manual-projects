#include "CountSort.h"

#include <vector>
#include <iostream>
#include <algorithm>


std::vector<int> counting_sort(std::vector<int> array) {

	std::vector<int> result(array.size(), 0);
	std::vector<int> count(*std::max_element(array.begin(), array.end()) + 1, 0);

	for (int number : array) {
		count[number] += 1;
	}

	for (int index = 1; index < count.size(); index++) {
		count[index] += count[index - 1];
	}

	std::reverse(array.begin(), array.end());

	for (int number : array) {
		count[number] -= 1;
		result[count[number]] = number;
	}

	return result;
}


template <typename T>
std::vector<T> production_counting_sort(std::vector<T> array) {

	std::vector<T> result(array.size(), 0);
	std::vector<int> count(*std::max_element(array.begin(), array.end()) + 1, 0);

	for (T data : array) {
		count[data] += 1;
	}

	for (int index = 1; index < count.size(); index++) {
		count[index] += count[index - 1];
	}

	std::reverse(array.begin(), array.end());

	for (T data : array) {
		count[data] -= 1;
		result[count[data]] = data;
	}

	return result;
}

