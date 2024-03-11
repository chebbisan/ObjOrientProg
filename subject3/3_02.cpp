#include <iostream>
#include <cstdlib>
#include <ctime>


int random_() {
    return 1 + std::rand() % 100;
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

    std::cout << '\n';
    int* new_array = new int[2*N];
    
    for (size_t i = 0; i < N; ++i) {
        new_array[i] = array[i];
        new_array[i+N] = array[i];
    }
    std::cout << "New array:\n";
    for (size_t i = 0; i < 2*N; ++i) {
        std::cout << new_array[i] << ' ';
    }
    std::cout << '\n';

    delete[] array;
    delete[] new_array;
    return 0;
}
