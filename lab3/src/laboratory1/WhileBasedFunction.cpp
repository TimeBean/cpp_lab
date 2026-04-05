#include "../../include/laboratory1/WhileBasedFunction.h"
#include "../../include/common/Result.h"
#include <cmath>

namespace Laboratory::FirstLaboratory {
    std::vector<Common::Result<double> > WhileBasedFunction::Compute() {
        auto result = std::vector<Common::Result<double> >();

        double x = A;
        double y;
        while (x < B) {
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

            x += STEP;
        }

        return result;
    }
}
