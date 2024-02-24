#include <cstdlib>
#include <iostream>
#include <ctime>

int random_(int a, int b) {
    return a + std::rand() % (b - a + 1);
}

int main() {
    std::srand(std::time(nullptr));
    int N, A, B;
    std::cout << "Enter size (N): ";
    std::cin >> N;
    std::cout << "Enter borders (A, B): ";
    std::cin >> A >> B;
    if (A > B || N < 1) {
        return -1;
    }

    int index_max = 0;
    int index_min = 0;
    int value_max = A - 1;
    int value_min = B + 1;

    int* array = new int[N];
    for (int i = 0; i < N; ++i) {
        array[i] = random_(A, B);
        std::cout << array[i] << ' ';
        if (array[i] > value_max) {
            value_max = array[i];
            index_max = i;
        }
        if (array[i] < value_min) {
            value_min = array[i];
            index_min = i;
        }
    }
    delete[] array;
    std::cout << "\nMax value: array[" << index_max << "] = " << value_max;
    std::cout << "\nMin value: array[" << index_min << "] = " << value_min << '\n';
    return 0;
}
