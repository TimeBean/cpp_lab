#include <iostream>
#include <cmath>
#include <iomanip>

constexpr double A = -3;
constexpr double B = 3;
constexpr double STEP = 0.3;

int main() {
    double x = A;
    double y;

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "    +-------+-------+" << std::endl;
    std::cout << "    |   x   |   y   |" << std::endl;
    std::cout << "    +-------+-------+" << std::endl;

    while (x < B) {
        if (x > 1) {
            y = exp(x);
        } else if (x < 0) {
            y = 2 * x - 1;
        } else {
            y = -1;
        }

        std::cout << "    | " << std::setw(5) << x << " | " << std::setw(5) << y << " |" << std::endl;

        x += STEP;
        std::cout << "    +-------+-------+" << std::endl;
    }

    return 0;
}
