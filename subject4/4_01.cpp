#include <iostream>
#include <cmath>

/*
Создайте структуру Point, представляющую точку в трехмерном
пространстве с координатами x, y, z. Напишите функцию, которая принимает
две точки и вычисляет расстояние между ними.
*/

struct Point {
    double x, y, z;
};

double distance(const Point& p1, const Point& p2) {
    return sqrt((p2.x - p1.x)*(p2.x - p1.x) + 
                (p2.y - p1.y)*(p2.y - p1.y) + 
                (p2.z - p1.z)*(p2.z - p1.z));
}

int main() {
    Point p1, p2;
    std::cout << "Enter point 1 (X, Y, Z): ";
    std::cin >> p1.x >> p1.y >> p1.z;
    std::cout << "Enter point 2 (X, Y, Z): ";
    std::cin >> p2.x >> p2.y >> p2.z;
    std::cout << "Distance between P1 and P2: " << distance(p1, p2) << '\n';
    return 0;

}
