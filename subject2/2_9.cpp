#include <iostream>

int main() {
    int A, B, M;
    std::cout << "Enter range (A; B): ";
    std::cin >> A >> B;
    std::cout << "Enter M: ";
    std::cin >> M;

    for (int i = A; i < B; ++i) {
        if (i % M == 0) {
            std::cout << i << ' ';
        }
    }
    std::cout << "\n End.\n";
    return 0;
}