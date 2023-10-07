#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef vector<int> vi;


vi count_sort(vi arr) {

	vi res(arr.size(), 0);
	vi c(*max_element(arr.begin(), arr.end()) + 1, 0);

	for (int i : arr) {
		c[i] += 1;
	}

	for (int j = 1; j < c.size(); j++) {
		c[j] += c[j - 1];
	}

	std::reverse(arr.begin(), arr.end());

	for (int i : arr) {
		c[i] -= 1;
		res[c[i]] = i;
	}

	return res;
}