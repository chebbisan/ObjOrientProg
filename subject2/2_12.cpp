#include <cstdlib>
#include <iostream>
#include <ctime>

int random_(int a, int b) {
    return a + std::rand() % (b - a + 1);
}

int main() {
    std::srand(std::time(nullptr));
    int N, A, B;
    std::cout << "Enter size (N): ";
    std::cin >> N;
    std::cout << "Enter borders (A, B): ";
    std::cin >> A >> B;
    if (A > B || N < 1) {
        return -1;
    }


    int* array = new int[N];
    for (int i = 0; i < N; ++i) {
        array[i] = random_(A, B);
        std::cout << array[i] << ' ';
    }
    std::cout << "\nLocal max indexes:\n";
    for (int i = 1; i < N - 1; ++i) {
        if (array[i] > array[i-1] && array[i] > array[i+1]){
            std::cout << i << ' ';
        }
    }
    std::cout << "\nEnd.\n";
    delete[] array;

}