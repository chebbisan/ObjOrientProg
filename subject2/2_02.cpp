
/*
Задание 2.2. Масса тела. Единицы массы пронумерованы следующим образом: 1
– килограмм, 2 – миллиграмм, 3 – грамм, 4 – тонна, 5 – центнер. Пользователь
вводит номер единицы массы N и массу тела M в этих единицах (значение
массы – вещественное число). Программа выводит на экран массу данного тела
в килограммах.
*/

#include <iostream>

int main() {
    double m;
    int n;
    // относительно килограмма
    // 1 - 10^0, 2 - 10^-6, 3 - 10^-3
    // 4 - 10^3, 5 - 10^2;

    std::cout << "Enter number and mass:\n";
    std::cin >> n >> m;
    // std::unordered_map...

    std::cout << "Mass is: ";
    switch(n) {
        case 1:
            std::cout << m << " kg\n";
            break;
        case 2:
            std::cout << m / 1000000 << " kg\n";
            break;
        case 3:
            std::cout << m / 1000 << " kg\n";
            break;
        case 4:
            std::cout << m * 1000 << " kg\n";
            break;
        case 5:
            std::cout << m * 100 << " kg\n";
            break;
        
        default:
            std::cout << "Unknown N\n";
            break;
    }
    return 0;
}