#include <iostream>
#include <vector>

int cash_dispenser(int amount_issued) {
    std::vector<int> nominals_banknots = { 5000, 1000, 100, 50, 10, 5, 1 };
    int count_banknots = 0;
    for (int nominal : nominals_banknots) {
        count_banknots += amount_issued / nominal;
        amount_issued %= nominal;
    }
    return count_banknots;
}