
/*
Задание 2.16. Двумерки, минмакс. Программа создает двумерный
целочисленный массив размером NxM элементов (задается константами),
инициализирует их случайными значениями в диапазоне (A;B) (задается
пользователем) и выводит на экран в виде матрицы. Программа находит
минимальный из максимальных элементов для каждой строки и выводит на
экран.
*/

#include <cstdlib>
#include <iostream>
#include <ctime>

int random_(int a, int b) {
    return a + std::rand() % (b - a);
}

int main() {
    std::srand(std::time(nullptr));
    int rows, cols, A, B;

    std::cout << "Enter size (N x M): ";
    std::cin >> rows >> cols;
    std::cout << "Enter borders (A, B): ";
    std::cin >> A >> B;
    if (A > B) {
        return -1;
    }

    int matrix[rows][cols];

    int max_row;
    int minimal = 1000000;

    for (int i = 0; i < rows; ++i) {
        max_row = -100000;
        std::cout << "[ ";
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = random_(A, B);
            std::cout << matrix[i][j] << ' ';
            if (matrix[i][j] > max_row) {
                max_row = matrix[i][j];
            }
        }
        std::cout << "]\n";
        if (max_row < minimal) {
            minimal = max_row;
        }
    }
    std::cout << "Minimal value (among max by row): " << minimal << '\n';
    return 0;
    
}