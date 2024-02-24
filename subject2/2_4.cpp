#include <iostream>
#include <cmath>
#include <string>

std::string solve(double a, double b, double c) {
    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0) {
        return "No real roots\n";
    }
    if (discriminant == 0) {
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