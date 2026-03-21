#include <algorithm>
#include <iostream>
#include <cmath>

constexpr double A = 1.1f;
constexpr double B = 2.6f;
// Только C влияет на ход исполнения программы. При необходимости заменить значение.
//constexpr double C = -3.1f;
constexpr double C = 3.1f;
constexpr double D = 4.2f;

int main() {
    std::cout << "Программа для вычисления функции." << std::endl;

    double x;
    std::cout << "Введите x > ";
    std::cin >> x;

    double z;
    // ReSharper disable once CppRedundantBooleanExpressionArgument
    if (C > 0 && x > 2) {
        z = std::max(std::max(C, x / C), sin(C));
        // ReSharper disable once CppDFAUnreachableCode
        // ReSharper disable once CppIfCanBeReplacedByConstexprIf
    } else if (C < 0 && x > 2) {
        // ReSharper disable once CppDFAUnreachableCode
        z = std::min(std::min(C, C * x + sin(B)), std::max(C, B));
    } else {
        z = std::max(C, B);
    }

    std::cout << "Z = " << z << std::endl;

    return 0;
}