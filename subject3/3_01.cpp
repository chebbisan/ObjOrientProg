#include <iostream>
#include <cstdlib>
#include <ctime>

#define N 20

int random_() {
    return std::rand() % 100;
}




int main() {
    std::srand(std::time(nullptr));
    int array[N];
    int* ptr = array;
    std::cout << "Array:\n";
    for (size_t i = 0; i < N; ++i) {
        array[i] = random_();
        std::cout << array[i] << ' ';
    }


    std::cout << "\nAfter:\n";
    for (size_t i = 0; i < N; ++i) {
        if (i % 2 == 0) {
            *(ptr+i) = 0;
        }
        std::cout << *(ptr+i) << ' ';
    }
    std::cout << '\n';

    

    return 0;
}