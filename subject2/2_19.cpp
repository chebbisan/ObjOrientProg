
/*
Задание 2.19. Двумерки, обнуление строк. Программа создает двумерный
целочисленный массив размером NxN элементов (задается константами),
инициализирует их случайными значениями в диапазоне (A;B) (задается
пользователем) и выводит на экран в виде матрицы. Пользователь вводит число,
а программа обнуляет строку с выбранным индексом, и выводит матрицу на
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

    int matrix[rows][rows];

    for (int i = 0; i < rows; ++i) {
        std::cout << "[ ";
        for (int j = 0; j < rows; ++j) {
            matrix[i][j] = random_(A, B);
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << "]\n";
    }

    std::cout << "Enter index of row (matrix_i, 1 <= i <= N): ";
    std::cin >> index;
    if (1 > index && rows < index) {
        std::cout << "Invalid index\n";
        return 0;
    }
    --index;

    for (int i = 0; i < rows; ++i) {
        std::cout << "[ ";
        for (int j = 0; j < rows; ++j) {
            if (i == index) {
                matrix[index][j] = 0;
            }
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << "]\n";
    }
    return 0;
    
}