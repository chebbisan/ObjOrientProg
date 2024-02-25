
/*
Задание 2.18. Двумерки, симметрия. Программа создает двумерный
целочисленный массив размером NxN элементов (задается константами),
инициализирует их случайными значениями в диапазоне (A;B) (задается
пользователем) и выводит на экран в виде матрицы. Программа выводит на
экран решение о том, является ли матрица симметричной.
*/

#include <cstdlib>
#include <iostream>
#include <ctime>

int random_(int a, int b) {
    return a + std::rand() % (b - a);
}

int main() {
    std::srand(std::time(nullptr));
    int rows, A, B;

    std::cout << "Enter size (N x N): ";
    std::cin >> rows;
    std::cout << "Enter borders (A, B): ";
    std::cin >> A >> B;
    if (A > B) {
        return -1;
    }

    int matrix[rows][rows];

    for (int i = 0; i < rows; ++i) {
        std::cout << "[ ";
        for (int j = 0; j < rows; ++j) {
            matrix[i][j] = random_(A, B);
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << "]\n";
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < rows; ++j) {
            if (matrix[i][j] != matrix[j][i]) {
                std::cout << "Not symmetrycal\n";
                return 0;
            }
        }
    } 
    std::cout << "Symmetrycal\n";
    return 0;
    
}