#include <cmath>
#include <vector>

#include "../../include/laboratory/DoWhileBasedFunction.h"

namespace Laboratory {
    std::vector<Common::Result<double> > DoWhileBasedFunction::Compute() const {
        auto result = std::vector<Common::Result<double> >();

        double t = 1;
        double y;
        do {
            if (t > A) {
                y = t * sqrt(t - A);
            }
            else if (t == A) {
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
