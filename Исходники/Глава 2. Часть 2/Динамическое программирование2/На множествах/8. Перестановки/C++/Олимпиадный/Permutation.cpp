#include <vector>
#include <algorithm>
#include <string>
#include <iostream>


int gcd(int number1, int number2) {
    while (number2 != 0) {
        int temp = number2;
        number2 = number1 % number2;
        number1 = temp;
    }
    return number1;
}


// ������� ���������� �������
std::vector<std::vector<int>> get_matrix(std::vector<int> permutation, int k) {
    std::vector<std::vector<int>> matrix;
    for (int number1 = 0; number1 < permutation.size(); number1++) {
        std::vector<int> row;
        for (int number2 = 0; number2 < permutation.size(); number2++) {
            if (gcd(permutation[number1], permutation[number2]) >= k 
                    and permutation[number1] != permutation[number2]) {
                row.push_back(1);
                continue;
            }
            row.push_back(0);
        }
        matrix.push_back(row);
    }
    return matrix;
}



std::vector<std::vector<int>> prepare(int len_permutation, std::vector<std::vector<int>> matrix) {
    std::vector<std::vector<int>> cnt_permutations_mask;
    for (int row = 0; row < (1 << len_permutation); row++) {
        cnt_permutations_mask.push_back(std::vector<int>(len_permutation, 0));
    }

    // ���� �� ����������
    for (int mask = 1; mask < (1 << len_permutation); mask++) {

        // ���� �� ��������� ���������
        for (int number = 0; number < len_permutation; number++) {

            // ���� ��������� ������� �� 1 ��������
            if (mask == (1 << number)) {
                cnt_permutations_mask[mask][number] = 1;
                continue;
            }

            cnt_permutations_mask[mask][number] = 0;

            // ���� ������� ����������� ���������
            if (mask & (1 << number)) {

                // ��������� ������� - �������� ������������ ������� ��������
                int pm = mask - (1 << number);
                for (int next_number = 0; next_number < len_permutation; next_number++) {

                    // �������, ����� �������� ����� ���� �������� ����� �������� i
                    if (matrix[number][next_number]) {
                        cnt_permutations_mask[mask][number] += cnt_permutations_mask[pm][next_number];
                    }
                }
            }
        }
    }
    return cnt_permutations_mask;
}


std::string find_permutation(int len_permutation, int m, int k, std::vector<int> permutation) {

    // ��������� ������������ - �������� ����������� � ������������������ �������
    std::sort(permutation.begin(), permutation.end());

    std::vector<std::vector<int>> matrix = get_matrix(permutation, k);
    std::vector<std::vector<int>> cnt_permutations_mask = prepare(len_permutation, matrix);

    int total = 0;
    int prev = 0;

    // ���������� ������ ���������� ������������
    for (int i = 0; i < len_permutation; i++) {
        total += cnt_permutations_mask[(1 << len_permutation) - 1][i];
    }

    // ���� ������������ ������ ��� m, �� ������� -1
    if (m > total) {
        return "-1";
    }

    // �������� ���������
    int mask = (1 << len_permutation) - 1;

    std::string res;

    // ���� �� �����
    for (int step = 1; step < len_permutation + 1; step++) {

        // ���� �� ��������� ���������
        for (int number = 0; number < len_permutation; number++) {

            // ���� ������� ����������� ���������
            if (mask & (1 << number)) {

                // ���� ������� �� ����� ���������� �� ���� ����� � ������������, �� ���������� �����
                if (step > 1 and (not matrix[prev][number])) {
                    continue;
                }

                // ���� m-�� ������������ 
                if (m > cnt_permutations_mask[mask][number]) {
                    m -= cnt_permutations_mask[mask][number];
                }

                // ������ �������, ������� ��������� �� ����� step � ������������ 
                else {
                    prev = number;
                    res += std::to_string(permutation[number]) + " ";

                    // �������� ��������� 
                    mask -= (1 << number);
                    break;
                }
            }
        }
    }
    return res;
}



