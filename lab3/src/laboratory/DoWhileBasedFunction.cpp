#include <cmath>
#include "../../include/laboratory/DoWhileBasedFunction.cpp.h"

namespace Laboratory {
    std::vector<Common::Result<double> > DoWhileBasedFunction::Compute() {
        auto result = std::vector<Common::Result<double> >();

        double t = 1;
        double y;
        do {
            if (t > kA) {
                y = t * sqrt(t - kA);
            }
            else if (t == kA) {
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

    std::vector<Common::Result<double>> DoWhileBasedFunction::Execute() const {
        return Compute();
    }
}
