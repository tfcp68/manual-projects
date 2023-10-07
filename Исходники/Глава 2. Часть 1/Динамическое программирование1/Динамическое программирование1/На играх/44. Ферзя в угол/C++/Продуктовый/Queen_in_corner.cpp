#include <vector>
#include <iostream>


// ������� ��������� ������� ����������
void fill_table(std::vector<std::vector<int>>& dp, int cnt_column, int cnt_row) {

    // ��������� ���������
    for (int curr_row = 0; curr_row < cnt_row; curr_row++) {
        dp[curr_row][cnt_column - 1] = 1;
    }

    // ��������� �����������
    for (int curr_column = 0; curr_column < cnt_column; curr_column++) {
        dp[cnt_row - 1][curr_column] = 1;
    }

    // ��������� ���������
    int curr_column = cnt_column - 1;
    for (int curr_row = cnt_row - 1; curr_row > -1; curr_row--) {
        if (curr_column >= 0) {
            dp[curr_row][curr_column] = 1;
            curr_column -= 1;
        }
    }
    
    dp[cnt_row - 1][cnt_column - 1] = 0;
}


// ������� ��� ����� �� ������
int winning_strategy(int cnt_row, int cnt_column, int x, int y) {
    
    // ������ �������
    std::vector<std::vector<int>> dp(cnt_row, std::vector<int>(cnt_column, 0));

    // ��������� ������ ���������, ����������� � ���������
    fill_table(dp, cnt_column, cnt_row);

    for (int curr_row = cnt_row - 2; curr_row > -1; curr_row--) {
        for (int curr_column = cnt_column - 2; curr_column > -1; curr_column--) {

            // ���������, ����� �� ��� ���� �� ������ � ��������
            if (dp[curr_row][curr_column + 1] and dp[curr_row + 1][curr_column] and dp[curr_row + 1][curr_column + 1]) {
                if (not dp[curr_row][curr_column]) {

                    // ������ � ������ 0 � ��������� ����������
                    // ��� ������, ������� ����� � �������
                    fill_table(dp, curr_column + 1, curr_row + 1);
                }
            }
        }
    }

    // ���� ����� ����������
    if (dp[y][x] == 1) {
        return 1;
    }

    return 2;
}




