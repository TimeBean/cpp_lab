#include <vector>
#include <cmath>
#include "../include/Laboratory/DoWhileBasedFunction.h"
#include "../include/Laboratory/utils/Result.h"

namespace Laboratory {
    std::vector<Result<double> > DoWhileBasedFunction::Execute() const noexcept {
        return Compute();
    }

    std::vector<Result<double>> DoWhileBasedFunction::Compute() {
        auto result = std::vector<Result<double> >();

        double t = 1;
        double y;
        do {
            if (t > kA) {
                y = t * sqrt(t - kA);
            }
            else if (std::abs(t - kA) < 1e-9) {
                y = t * sin(kA * t);
            }
            else if (t < kA) {
                y = exp(-kA * t) * cos(kA * t);
            }

            result.emplace_back(t, y);
            t += kDeltaT;
        } while (t <= 5);

        return result;
    }
}
