#include <iostream>
#include "vector"

using namespace std;


int RepetitionPlacement(int k, int N) {
    int result = 1;
    for (int i = 0; i < k; i++) {
        result *= N;
    }
    return result;
}

vector<int> __shift(vector<int> a, int N) {
    for (int i = a.size() - 1; i > 0; i--) {
        if (a[i] >= N) {
            a[i] = 0;
            a[i-1] += 1;
        } else {
            break;
        }
    }
    return a;
}

vector<vector<int> > RepetitionPlacement_generation(int k, int N) {
    int per = RepetitionPlacement(k, N);
    vector<int> a;
    vector<vector<int> > result;
    for (int i = 0; i < k; ++i) {
        a.push_back(0);
    }
    for (int i = 0; i < per; i++) {
        result.push_back(a);
        a[k-1] += 1;
        a = __shift(a, N);
    }
    return result;
}

vector<int> RepetitionPlacement_number(int k, int N, int number) {
    vector<int>  result;
    for (int i = 0; i < k; ++i) {
        result.push_back(0);
    }
    for (int i = 0; i < k; ++i) {
        int plac = RepetitionPlacement(k - i - 1, N);
        result[i] = number / plac;
        number = number % plac;
    }
    return result;
}

int RepetitionPlacement_plac(int k, int N, vector<int> placement) {
    int result = 0;
    for (int i = 0; i < placement.size(); i++) {
        int plac = RepetitionPlacement(k - i - 1, N);
        result += plac * placement[i];
    }
    return result;
}

vector<int> RepetitionPlacement_plac_plus_1(int k, int N, vector<int> placement) {
        placement[placement.size()-1] += 1;
    return __shift(placement, N);
}

