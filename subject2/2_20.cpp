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
    return 0;
    
}