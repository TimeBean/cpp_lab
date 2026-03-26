#include <iostream>
#include <cmath>
#include <iomanip>

double get_d(double x, double y) {
    const double denominator = x * (x - y) * (3 * x + y);
    if (std::abs(denominator) < 1e-9) {
        throw std::runtime_error("Деление на ноль.");
    }

    const double d = (x * exp(x * y) + 8 * sin(x) * sin(x)) /
                     denominator;

    return d;
}

int main() {
    //Тестовые значения: x = 1,002; y = -0.5321. Ожидается d = 1,6480.
    std::cout << "Программа для вычисления формулы.\n";

    double x, y;
    std::cout << "Введите x: ";
    if (!(std::cin >> x)) {
        std::cerr << "Введенная строка некорректна. Ожидалось число.\n";
        return 1;
    }
    std::cout << "Введите y: ";
    if (!(std::cin >> y)) {
        std::cerr << "Введенная строка некорректна. Ожидалось число.\n";
        return 1;
    }

    try {
        const double d = get_d(x, y);
        std::cout << "d = " << std::fixed << std::setprecision(4) << d << '\n';
    } catch (std::runtime_error const &e) {
        std::cerr << e.what() << '\n';
        return 1;
    }

    return 0;
}
