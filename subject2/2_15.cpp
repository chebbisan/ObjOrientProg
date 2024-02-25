
/*
Задание 2.15. Проход по массиву с переворотом 2. То же самое, что 2.14, но
вместо использования второго массива используйте одну переменную
*/

#include <cstdlib>
#include <iostream>
#include <ctime>

int random_(int a, int b) {
    return a + std::rand() % (b - a);
}

int main() {
    std::srand(std::time(nullptr));
    int N, A, B;
    std::cout << "Enter size (N): ";
    std::cin >> N;
    std::cout << "Enter borders (A, B): ";
    std::cin >> A >> B;
    if (A > B) {
        return -1;
    }


    int* array = new int[N];
    for (int i = 0; i < N; ++i) {
        array[i] = random_(A, B);
        std::cout << array[i] << ' ';
    }
    std::cout << '\n';
    for (int i = N - 1; i > -1; --i) {
        std::cout << array[i] << ' ';
    }
    std::cout << '\n';
    delete[] array;
    return 0;
}