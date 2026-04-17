#include <iostream>
#include <cmath>

constexpr double A = 1.1;
constexpr double B = 2.6;
constexpr double D = 4.2;

int main() {
    std::cout << "A program for calculating a function.\n";

    std::string isVariableCGreaterThanZero;
    std::cout << "Is coefficient C greater than zero? [Y/n] ";
    std::getline(std::cin, isVariableCGreaterThanZero);
    double c;
    if (isVariableCGreaterThanZero.empty() || isVariableCGreaterThanZero == "Y" || isVariableCGreaterThanZero == "y") {
        c = 3.1;
    } else {
        c = -3.1;
    }

    std::cout << "С = " << c << '\n';

    double x;
    std::cout << "Enter x: ";
    if (!(std::cin >> x)) {
        std::cerr << "The string you entered is invalid. A number was expected.\n";
        return 1;
    }

    double z;
    if (c > 0 && x > 2) {
        z = std::max(std::max(c, x / c), sin(c));
    } else if (c < 0 && x > 2) {
        const double t1 = c * x + sin(B);
        const double t2 = std::max(c, B);
        const double t3 = std::min(c, t1);
        z = std::min(t3, t2);
    } else {
        z = std::max(c, B);
    }
    std::cout << "Z = " << z << '\n';

    return 0;
}
