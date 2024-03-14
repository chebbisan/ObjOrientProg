#include <iostream>
#include <cstdlib>
#include <ctime>


/*
Создать динамический массив целых чисел и заполнить случайными
значениями. Написать функцию, которая принимает этот массив и его размер, а
затем возвращает указатель на новый массив, содержащий только четные числа,
стоящие на нечетной позиции из исходного массива (возвращаемый массив того
же размера, но остальные позиции заполнены нулями).
*/

int random_() {
    return 1 + std::rand() % 100;
}

int* modify_array(int array[], size_t size) {
    int* modified = new int[size];
    for (size_t i = 0; i < size; ++i) {
        if (i % 2 != 0 && array[i] % 2 == 0) {
            modified[i] = array[i];
        } else {
            modified[i] = 0;
        }
    }
    return modified;
}

int main() {
    std::srand(std::time(nullptr));
    int N;
    std::cout << "Enter array size: ";
    std::cin >> N;
    int* array = new int[N];
    std::cout << "Array:\n";
    for (size_t i = 0; i < N; ++i) {
        array[i] = random_();
        std::cout << array[i] << ' ';
    }
    std::cout << "\nModified: \n";
    int* modified = modify_array(array, N);
    for (size_t i = 0; i < N; ++i) {
        std::cout << modified[i] << ' ';
    }
    std::cout << '\n';
    
    delete[] modified;
    delete[] array;
    return 0;
}
