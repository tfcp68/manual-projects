#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

vi count_sort_negative(vi arr) {

	int l = *min_element(arr.begin(), arr.end());
	int h = *max_element(arr.begin(), arr.end());

	vi res(arr.size(), 0);
	vi c(h - l + 1, 0);

	for (int i : arr) {
		c[i - l] += 1;
	}

	for (int j = 1; j < c.size(); j++) {
		c[j] += c[j - 1];
	}

	reverse(arr.begin(), arr.end());

	for (int i : arr) {
		c[i - l] -= 1;
		res[c[i - l]] = i;
	}

	return res;
}