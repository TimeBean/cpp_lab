#include <cmath>
#include <vector>

#include "../../include/laboratory/ForBasedFunction.h"

namespace Laboratory {
    std::vector<Common::Result<double> > ForBasedFunction::Compute(double x) {
        auto result = std::vector<Common::Result<double> >();

        double sum = 0;
        for (int n = 3; n <= 8; n++) {
            sum += std::exp(n) * x * x / (2 * n + 1);
        }

        result.emplace_back(x, sum);

        return result;
    }
}
