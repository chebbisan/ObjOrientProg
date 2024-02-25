
/*
Задание 2.14. Проход по массиву с переворотом. Программа спрашивает у
пользователя три числа A, B и N. После чего генерирует и выводит на экран
массив N целых чисел расположенных в диапазоне (A;B). Программа
переворачивает значение в массиве используя второй массив и выводит на
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
    int* reverse_array = new int[N];
    for (int i = 0; i < N; ++i) {
        reverse_array[i] = array[N - 1 - i];
        std::cout << reverse_array[i] << ' ';
    }
    std::cout << '\n';

    delete[] array;
    delete[] reverse_array;
    return 0;
}
