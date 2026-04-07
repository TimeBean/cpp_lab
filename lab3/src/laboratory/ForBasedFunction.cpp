#include <cmath>
#include <iostream>
#include "../../include/laboratory/ForBasedFunction.h"

namespace Laboratory {
    std::vector<Common::Result<double> > ForBasedFunction::Compute(double input) {
        std::vector<Common::Result<double> > result;

        double sum = 0;
        for (int n = 3; n <= 8; n++) {
            sum += std::exp(n) * input * input / (2 * n + 1);
        }

        result.emplace_back(input, sum);
        return result;
    }

    std::vector<Common::Result<double> > ForBasedFunction::Execute() const {
        std::cout << "Введите x: ";
        double x;

        if (!(std::cin >> x)) {
            const std::string message =
                    "Введенная строка некорректна. Ожидалось число.";
            std::cerr << message << '\n';
            throw std::runtime_error(message);
        }

        return Compute(x);
    }
}
