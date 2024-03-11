#include <iostream>
#include <cstdlib>
#include <ctime>

#define N 20

int random_() {
    return 1 + std::rand() % 100;
}


int* getMaxElem(int* arr, size_t size) {
    int* max_ptr = nullptr;
    int max_val = -2147483648;
    for (size_t i = 0; i < size; ++i) {
        if (*(arr+i) > max_val) {
            max_ptr = arr + i;
            max_val = *(arr + i);
        }
    }
    return max_ptr;
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

    int* max_ptr = getMaxElem(ptr, N);
    std::cout << "\nMax val: " << *max_ptr << ", Ptr: " << max_ptr << '\n';
    return 0;
}
