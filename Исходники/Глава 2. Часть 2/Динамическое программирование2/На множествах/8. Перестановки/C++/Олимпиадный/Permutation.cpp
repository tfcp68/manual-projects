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


// Функция построения матрицы
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

    // Цикл по множествам
    for (int mask = 1; mask < (1 << len_permutation); mask++) {

        // Цикл по элементам множества
        for (int number = 0; number < len_permutation; number++) {

            // Если множество состоит из 1 элемента
            if (mask == (1 << number)) {
                cnt_permutations_mask[mask][number] = 1;
                continue;
            }

            cnt_permutations_mask[mask][number] = 0;

            // Если элемент принадлежит множеству
            if (mask & (1 << number)) {

                // Исключаем элемент - получаем подмножество меньшей мощности
                int pm = mask - (1 << number);
                for (int next_number = 0; next_number < len_permutation; next_number++) {

                    // Смотрим, какие элементы могут быть записаны после элемента i
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

    // Сортируем перестановку - получаем минимальную в лексикографическом порядке
    std::sort(permutation.begin(), permutation.end());

    std::vector<std::vector<int>> matrix = get_matrix(permutation, k);
    std::vector<std::vector<int>> cnt_permutations_mask = prepare(len_permutation, matrix);

    int total = 0;
    int prev = 0;

    // Вычисление общего количества перестановок
    for (int i = 0; i < len_permutation; i++) {
        total += cnt_permutations_mask[(1 << len_permutation) - 1][i];
    }

    // Если перестановок меньше чем m, то выводим -1
    if (m > total) {
        return "-1";
    }

    // Исходное множество
    int mask = (1 << len_permutation) - 1;

    std::string res;

    // Цикл по шагам
    for (int step = 1; step < len_permutation + 1; step++) {

        // Цикл по элементам множества
        for (int number = 0; number < len_permutation; number++) {

            // Если элемент принадлежит множеству
            if (mask & (1 << number)) {

                // Если элемент не может находиться на этом месте в перестановке, то продолжаем поиск
                if (step > 1 and (not matrix[prev][number])) {
                    continue;
                }

                // Ищем m-ую перестановку 
                if (m > cnt_permutations_mask[mask][number]) {
                    m -= cnt_permutations_mask[mask][number];
                }

                // Найдем элемент, который находится на месте step в перестановке 
                else {
                    prev = number;
                    res += std::to_string(permutation[number]) + " ";

                    // Изменяем множество 
                    mask -= (1 << number);
                    break;
                }
            }
        }
    }
    return res;
}



