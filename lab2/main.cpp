#include <iostream>
#include <cmath>

constexpr double A = 1.1;
constexpr double B = 2.6;
constexpr double D = 4.2;

int main() {
    std::cout << "Программа для вычисления функции.\n";

    std::string is_c_greater_than_0;
    std::cout << "Коэффициент C больше нуля? [Y/n] ";
    std::getline(std::cin, is_c_greater_than_0);
    double C;
    if (is_c_greater_than_0.empty() || is_c_greater_than_0 == "Y" || is_c_greater_than_0 == "y") {
        C = 3.1;
    } else {
        C = -3.1;
    }

    std::cout << "С = " << C << '\n';

    double x;
    std::cout << "Введите x: ";
    if (!(std::cin >> x)) {
        std::cerr << "Введенная строка некорректна. Ожидалось число.\n";
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
