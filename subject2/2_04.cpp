
/*
Задание 2.4. Уравнение до 2-го порядка. Пользователь вводит коэффициенты
уравнения вида ax 2 + bx + c = 0. Программа выводит решение данного
уравнения. Учтите все возможные комбинации коэффициентов.
*/

#include <iostream>
#include <cmath>

struct complex {
    double Re, Im;
};

std::string solve(double a, double b, double c) {
    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0) {
        complex comp;
        comp.Re = -b / (2 * a);
        comp.Im = sqrt(abs(discriminant)) / (2 * a);
        return "The roots are " + std::to_string(comp.Re) + " ± " + std::to_string(comp.Im) + "i\n";
        
    }
    else if (discriminant == 0) {
        double x = -b / (2 * a);
        return "The root is " + std::to_string(x) + "\n";
    }
    double x1 = (-b - sqrt(discriminant)) / (2 * a);
    double x2 = (-b + sqrt(discriminant)) / (2 * a);
    return "The roots are " + std::to_string(x1) + " and " + std::to_string(x2) + "\n";
}

int main() {
    double a, b, c;
    std::cout << "Enter coefficients: ";
    std::cin >> a >> b >> c;
    
    std::cout << solve(a, b, c);
    return 0;
}
