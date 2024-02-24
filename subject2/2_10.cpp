#include <iostream>

bool is_prime(const int& n) {
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int next_prime(int n) {
    if (n == 2) {
        return 3;
    }
    
    do {
        n += 2;
    } while (!is_prime(n));
    return n;
}

int main() {
    int N;
    std::cout << "Enter N: ";
    std::cin >> N;
    int counter = 0;
    int prime = 2;
    while (counter < N) {
        std::cout << prime << ' ';
        ++counter;
        prime = next_prime(prime);
    }
    std::cout << "\nEnd.\n";
    return 0;
}