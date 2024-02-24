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