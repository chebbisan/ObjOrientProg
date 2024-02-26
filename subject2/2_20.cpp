
/*
Задание 2.20. Двумерки, обнуление столбцов. Программа создает двумерный
целочисленный массив размером NxN элементов (задается константами),
инициализирует их случайными значениями в диапазоне (A;B) (задается
пользователем) и выводит на экран в виде матрицы. Пользователь вводит число,а программа обнуляет столбец с выбранным индексом, и выводит матрицу на
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
    int rows, A, B, index;

    std::cout << "Enter size (N x N): ";
    std::cin >> rows;
    std::cout << "Enter borders (A, B): ";
    std::cin >> A >> B;
    if (A > B) {
        return -1;
    }

    int** matrix = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[rows];
    }

    for (int i = 0; i < rows; ++i) {
        std::cout << "[ ";
        for (int j = 0; j < rows; ++j) {
            matrix[i][j] = random_(A, B);
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << "]\n";
    }

    std::cout << "Enter index of column (matrix_i, 1 <= i <= N): ";
    std::cin >> index;
    if (1 > index && rows < index) {
        std::cout << "Invalid index\n";
        return 0;
    }
    --index;

    for (int i = 0; i < rows; ++i) {
        std::cout << "[ ";
        for (int j = 0; j < rows; ++j) {
            if (j == index) {
                matrix[i][index] = 0;
            }
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << "]\n";
    }

    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
    
}