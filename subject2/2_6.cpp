#include <iostream>
#include <cmath>

int main() {
    double H1, D, L, H2, R;
    std::cout << "Enter H1, D, L, H2, R: " << '\n';
    std::cin >> H1 >> D >> L >> H2 >> R;
    double V1 = H1 * D * L;
    double V2 = M_PI * R * R * H2;
    std::cout << V1 / V2 << " wineglasses are needed to fill aquarium\n";
    return 0;
}