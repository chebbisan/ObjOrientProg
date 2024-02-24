#include <iostream>

int main() {
    
    double m;
    int from, to;
    // относительно килограмма
    // 1 - 10^0, 2 - 10^-6, 3 - 10^-3
    // 4 - 10^3, 5 - 10^2;

    std::cout << "Enter number and mass:\n";
    std::cin >> from >> m;
    // std::unordered_map...

    switch(from) {
        case 1:
            break;
        case 2:
            m = m / 1000000;
            break;
        case 3:
            m = m / 1000;
            break;
        case 4:
            m = m * 1000;
            break;
        case 5:
            m = m * 100;
            break;
        
        default:
            std::cout << "Unknown N\n";
            break;
    }

    std::cout << "Convert to: ";
    std::cin >> to;
    std::cout << "Mass is: ";

    switch(to) {
        case 1:
            std::cout << m << " kg\n"; 
            break;
        case 2:
            std::cout << m * 1000000 << " mg\n";
            break;
        case 3:
            std::cout << m * 1000 << " g\n";
            break;
        case 4:
            std::cout << m / 1000 << " tn\n";
            break;
        case 5:
            std::cout << m / 100 << " cwt\n";
            break;
        
        default:
            std::cout << "Unknown N\n";
            break;
    }

    return 0;
}