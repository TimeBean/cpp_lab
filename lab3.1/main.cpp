#include <iostream>
#include <cmath>
#include <iomanip>

constexpr double A = -3;
constexpr double B = 3;
constexpr double STEP = 0.3;

int main() {
    double x = A;

    std::cout << "Программа для вычисления значений функций в диапазоне от " << A << " до " << B << " с шагом " << STEP
            << std::endl << std::endl;

    std::cout << "    +-------+-------+" << std::endl;
    std::cout << "    |   x   |   y   |" << std::endl;
    std::cout << "    +-------+-------+" << std::endl;

    std::cout << std::fixed << std::setprecision(2);

    while (x < B) {
        double y;

        if (x > 1) {
            y = exp(x);
        } else if (x < 0) {
            y = 2 * x - 1;
        } else {
            y = -1;
        }

        if (y > 0) {
            std::cout << "    | " << std::setw(5) << x << " | " << std::setw(5) << y << " |" << std::endl;

            std::cout << "    +-------+-------+" << std::endl;
        }

        x += STEP;
    }

    return 0;
}
