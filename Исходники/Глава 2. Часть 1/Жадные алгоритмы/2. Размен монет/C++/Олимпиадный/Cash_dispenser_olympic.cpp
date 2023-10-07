#include <iostream>
#include <vector>

int cash_dispenser(int N) {
    std::vector<int> nominals = { 5000, 1000, 100, 50, 10, 5, 1 };
    int count = 0;
    for (int i : nominals) {
        count += N / i;
        N %= i;
    }
    return count;
}