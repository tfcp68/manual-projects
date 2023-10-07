#include <iostream>
#include <vector>
#include <string>


void first_step(int n, std::vector<int> coins, std::vector<std::vector<int>> &dp,
                std::vector<std::vector<std::string>> &path) {
    for (int i = 0; i < n; i++) {
        dp[i][i] = coins[i];
        path[i][i] = std::to_string(coins[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        dp[i][i + 1] = std::max(coins[i], coins[i + 1]);
        path[i][i + 1] = std::to_string(dp[i][i + 1]);
    }
    return;
}


std::pair<int, std::string> coin_in_line(std::vector<int> coins) {
    int n = coins.size();
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));
    std::vector<std::vector<std::string>> path(n, std::vector<std::string>(n, ""));

    first_step(n, coins, dp, path);

    for (int gap = 2; gap < n; gap++) {
        for (int i = 0; i < (n - gap); i++) {
            int j = i + gap;

            int choose_left = coins[i] + std::min(dp[i + 2][j], dp[i + 1][j - 1]);
            int choose_right = coins[j] + std::min(dp[i + 1][j - 1], dp[i][j - 2]);
;           dp[i][j] = std::max(choose_left, choose_right);

            if (choose_left > choose_right)
                path[i][j] = std::to_string(coins[i]) + " " + path[i + 2][j];
            else
                path[i][j] = std::to_string(coins[j]) + " " + path[i][j - 2];
        }

    }
    return { dp[0][n - 1], path[0][n - 1] };
}


int main() {
    std::vector<int> coins = {2, 3, 7, 10};
    std::pair<int, std::string> res = coin_in_line(coins);

    std::cout << res.first << std::endl;
    std::cout << res.second << std::endl;
    return 0;
}