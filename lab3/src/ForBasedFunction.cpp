#include <cmath>
#include <iostream>
#include <stdexcept>
#include <vector>

#include "../include/Laboratory/ForBasedFunction.h"
#include "../include/Laboratory/utils/Result.h"

namespace Laboratory {
    std::vector<Result<double> > ForBasedFunction::Compute(double input) {
        std::vector<Result<double> > result;

        double sum = 0;
        for (int n = 3; n <= 8; ++n) {
            sum += std::exp(static_cast<double>(n)) * input * input
                    / static_cast<double>(2 * n + 1);
        }

        result.emplace_back(input, sum);
        return result;
    }

    std::vector<Result<double> > ForBasedFunction::Execute() const {
        std::cout << "Enter x: ";
        double x;

        if (!(std::cin >> x)) {
            const std::string message =
                    "The string you entered is invalid. A number was expected.";
            std::cerr << message << '\n';
            throw std::runtime_error(message);
        }

        return Compute(x);
    }
}
