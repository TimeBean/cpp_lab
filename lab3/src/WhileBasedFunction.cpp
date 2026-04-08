#include <vector>
#include <cmath>
#include "../include/Laboratory/WhileBasedFunction.h"
#include "../include/Laboratory/utils/Result.h"

namespace Laboratory {
    std::vector<Result<double> > WhileBasedFunction::Execute() const noexcept {
        return Compute();
    }

    std::vector<Result<double>> WhileBasedFunction::Compute()  {
        auto result = std::vector<Result<double> >();

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
}
