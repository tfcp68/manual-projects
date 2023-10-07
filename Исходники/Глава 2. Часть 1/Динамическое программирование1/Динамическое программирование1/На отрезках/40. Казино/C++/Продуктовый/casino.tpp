#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

template<typename ValueType>
ValueType casino(const unordered_map<ValueType, ValueType> &cost, const string &s, ValueType m, const vector<string> &w) {
    ValueType n = s.length();
    std::vector<ValueType> prefix_arr(n, 0);
    std::vector<std::vector<std::vector<std::vector<bool>>>>hyper_bool(n, vector<std::vector<std::vector<bool>>>
            (n, std::vector<std::vector<bool>>(m, std::vector<bool>(n, false))));
    std::vector<std::vector<bool>> bool_(n, std::vector<bool>(n, false));
    std::vector<std::vector<ValueType>> max_win(n, std::vector<ValueType>(n, 0));

    prefix_arr[0] = cost.at(s[0]);
    for (int i = 1; i < n; i++) {
        prefix_arr[i] = prefix_arr[i - 1] + cost.at(s[i]);
    }

    // подготовка для вычисления bool
    for (int len_ = 0; len_ < n; len_++) {
        for (int i = 0; i < n - len_; i++) {
            int j = len_ + i;
            for (int k = 0; k < m; k++) {
                if (i == j) {
                    if (s[i] == w[k][0]) {
                        hyper_bool[i][j][k][0] = true;
                    } else {
                        hyper_bool[i][j][k][0] = false;
                    }
                    continue;
                }

                for (int p = 1; p < w[k].length(); p++) {
                    if (s[j] != w[k][p]) {
                        continue;
                    }
                    for (int x = i; x < j; x++) {
                        if (hyper_bool[i][x][k][p - 1] && (x == j - 1 || bool_[x + 1][j - 1])) {
                            hyper_bool[i][j][k][p] = true;
                        }
                    }
                }

                if (hyper_bool[i][j][k][w[k].length() - 1]) {
                    bool_[i][j] = true;
                }

                for (int k = i; k < j; k++) {
                    if (bool_[i][k] && bool_[k + 1][j]) {
                        bool_[i][j] = true;
                    }
                }
            }
        }
    }

    // вычисление подзадачи bool

    for (int len_ = 0; len_ < n; len_++) {
        for (int i = 0; i < n - len_; i++) {
            int j = i + len_;
            for (int k = i; k < j; k++){
                if (bool_[i][k] && bool_[k + 1][j]){
                    bool_[i][j] = true;
                }
            }
        }
    }

    // вычисление подзадачи max_win
    for (int len_ = 0; len_ < n; len_++) {
        for (int i = 0; i < n - len_; i++) {
            int j = i + len_;
            if (bool_[i][j]) {
                max_win[i][j] = prefix_arr[j] - prefix_arr[i - 1];
                if (i == 0){
                    max_win[i][j] = prefix_arr[j] - 0;
                }
                continue;
            }
            for (int k = i + 1; k < j; k++) {
                max_win[i][j] = std::max(max_win[i][j], max_win[i][k - 1] + max_win[k + 1][j]);
            }
        }
    }

    return max_win[0][n - 1];
}

