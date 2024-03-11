#include <iostream>

char* concate(char* f, char* s, size_t fs, size_t ss) {
    char* c = new char[fs+ss];
    for (size_t i = 0; i < fs + ss; ++i) {
        if (i < fs) {
            c[i] = f[i];
        } else {
            c[i] = s[i-fs];
        }
    }
    return c;
}

int main() {
    int N, M;
    std::cout << "Enter N, M: ";
    std::cin >> N >> M;
    char* hello = new char[N];
    char* world = new char[M];
    std::cout << "Enter first word: ";
    std::cin >> hello; 
    std::cout << "Enter second word: ";
    std::cin >> world; 

    char* helloworld = concate(hello, world, N, M);
    std::cout << helloworld << '\n';

    delete[] hello;
    delete[] world;
    delete[] helloworld;
    return 0;
}