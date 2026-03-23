#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    std::cout << "Программа для вычисления функции. " << std::endl;
    std::cout << "Тестовые значения: x = 1,002; y = -0.5321. Ожидается d = 1,6480." << std::endl;

    double x, y;
    std::cout << "Введите x > ";
    std::cin >> x;
    std::cout << "Введите y > ";
    std::cin >> y;

    const double d = (x * exp(x * y) + 8 * pow(sin(x), 2)) /
                     (x * (x - y) * (3 * x + y));

    std::cout << "d = " << std::fixed << std::setprecision(4) << d << std::endl;

    return 0;
}
