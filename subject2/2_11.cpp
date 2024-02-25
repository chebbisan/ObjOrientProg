
/*
Задание 2.11. Контролируемая случайность. Программа спрашивает у
пользователя три числа A, B и N. После чего генерирует и выводит на экран
массив N целых чисел расположенных в диапазоне (A;B). Программа выводит
среднее арифметическое всех четных элементов, стоящих на нечетных
позициях.
*/

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
    int sum = 0;
    int counter = 0;

    int* array = new int[N];
    for (int i = 0; i < N; ++i) {
        array[i] = random_(A, B);
        std::cout << array[i] << ' ';
        if (i % 2 != 0 && array[i] % 2 == 0) {
            sum += array[i];
            ++counter;
        }
    }
    std::cout << '\n';
    delete[] array;
    std::cout << "Average: " << sum / counter << '\n';

    return 0;
}