#include <cmath>
#include <iostream>

struct Point {
    double x;
    double y;
    double z;
};

Point CrossProduct(const Point& v1, const Point& v2) {
    Point cross_prod;
    cross_prod.x = v1.y * v2.z - v1.z * v2.y;
    cross_prod.y = v1.z * v2.x - v1.x * v2.z;
    cross_prod.z = v1.x * v2.y - v1.y * v2.x;
    return cross_prod;
}

int main() {
    Point p1, p2, p3, point_M;
    std::cout << "Enter point1 (x, y, z): ";
    std::cin >> p1.x >> p1.y >> p1.z;

    std::cout << "Enter point2 (x, y, z): ";
    std::cin >> p2.x >> p2.y >> p2.z;

    std::cout << "Enter point3 (x, y, z): ";
    std::cin >> p3.x >> p3.y >> p3.z;

    std::cout << "Enter point_M (x, y, z): ";
    std::cin >> point_M.x >> point_M.y >> point_M.z;

    // 3dVectors
    Point vector1;
    Point vector2;
    vector1.x = p2.x - p1.x;
    vector1.y = p2.y - p1.y;
    vector1.z = p2.z - p1.z;

    vector2.x = p3.x - p1.x;
    vector2.y = p3.y - p1.y;
    vector2.z = p3.z - p1.z;

    Point cross = CrossProduct(vector1, vector2);
    // Plane coeff
    double A = cross.x;
    double B = cross.y;
    double C = cross.z;
    double D = -(A * p1.x + B * p1.y + C * p1.z);

    double r = abs(A * point_M.x + B * point_M.y + C * point_M.z + D) / sqrt(A*A + B*B + C*C);
    std::cout << "Range is: " << r << '\n';
}