#include <iostream>
#include <cmath>
#include <iomanip>

double get_d(double x, double y) {
    return (x * exp(x * y) + 8 * pow(sin(x), 2)) /
           (x * (x - y) * (3 * x + y));
}

int main() {
    //Тестовые значения: x = 1,002; y = -0.5321. Ожидается d = 1,6480.
    std::cout << "Программа для вычисления формулы. " << std::endl;

    double x, y;
    std::cout << "Введите x > ";
    if (!(std::cin >> x)) {
        return 1;
    }
    std::cout << "Введите y > ";
    if (!(std::cin >> y)) {
        return 1;
    }

    const double d = get_d(x, y);
    std::cout << "d = " << std::fixed << std::setprecision(4) << d << std::endl;

    return 0;
}
