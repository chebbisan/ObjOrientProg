
/*
Задание 2.1. Баловство с ящичками. Пользователь вводит три переменные: X, Y,
Z. Если значения переменных упорядочены по убыванию, программа удваивает
их; в противном случае заменяет значение каждой переменной на
противоположное. Программа выводит значения X, Y, Z на экран.
*/


#include <iostream>

int main() {
    int X, Y, Z;

    std::cout << "Enter values: ";
    std::cin >> X >> Y >> Z;

    if (X >= Y && Y >= Z) {
        X *= 2;
        Y *= 2;
        Z *= 2;
    } else {
        X = -X;
        Y = -Y;
        Z = -Z;
    }

    std::cout << "Result: " << X << ' ' << Y << ' ' << Z << '\n';
    return 0;
}