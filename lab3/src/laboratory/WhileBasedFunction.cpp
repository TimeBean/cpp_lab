#include <cmath>
#include <iostream>
#include "../../include/laboratory/WhileBasedFunction.cpp.h"

namespace Laboratory {

    inline std::vector<Common::Result<double>> WhileBasedFunction::Compute() {
        auto result = std::vector<Common::Result<double> >();

        double x = kA;
        double y;
        while (x < kB) {
            if (x > 1) {
                y = std::exp(x);
            } else if (x < 0) {
                y = 2 * x - 1;
            } else {
                y = -1;
            }

            if (y > 0) {
                result.emplace_back(x, y);
            }

            x += kStep;
        }

        return result;
    }

    inline std::vector<Common::Result<double>> WhileBasedFunction::Execute() const {
        return Compute();
    }
}
