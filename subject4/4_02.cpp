#include <iostream>

/*
Создайте структуру Rectangle, описывающую прямоугольник с
полями ширины и высоты. Напишите функцию, которая принимает
прямоугольник в качестве аргумента и вычисляет его площадь.
*/

struct Rectangle {
    double height, width;
};

double area(const Rectangle& r) {
    return r.height * r.width;
}

int main() {
    Rectangle r1;
    r1.height = 13;
    r1.width = 20;
    return 0;
}