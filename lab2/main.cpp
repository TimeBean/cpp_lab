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
    double C;
    if (isVariableCGreaterThanZero.empty() || isVariableCGreaterThanZero == "Y" || isVariableCGreaterThanZero == "y") {
        C = 3.1;
    } else {
        C = -3.1;
    }

    std::cout << "С = " << C << '\n';

    double x;
    std::cout << "Enter x: ";
    if (!(std::cin >> x)) {
        std::cerr << "The string you entered is invalid. A number was expected.\n";
        return 1;
    }

    double z;
    if (C > 0 && x > 2) {
        z = std::max(std::max(C, x / C), sin(C));
    } else if (C < 0 && x > 2) {
        const double t1 = C * x + sin(B);
        const double t2 = std::max(C, B);
        const double t3 = std::min(C, t1);
        z = std::min(t3, t2);
    } else {
        z = std::max(C, B);
    }
    std::cout << "Z = " << z << '\n';

    return 0;
}
