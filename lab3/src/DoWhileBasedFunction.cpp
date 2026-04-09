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
            if (t > A) {
                y = t * sqrt(t - A);
            }
            else if (std::abs(t - A) < 1e-9) {
                y = t * sin(A * t);
            }
            else if (t < A) {
                y = exp(-A * t) * cos(A * t);
            }

            result.emplace_back(t, y);
            t += DeltaT;
        } while (t <= 5);

        return result;
    }
}
