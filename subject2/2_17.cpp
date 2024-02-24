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
    std::cout << '\n';
    for (int i = 0; i < rows; ++i) {
        std::cout << "[ ";
        for (int j = 0; j < rows; ++j) {
            if (i != j) {
                matrix[i][j] = 1;
            }
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << "]\n";

    }

    std::cout << '\n';
    return 0;
    
}