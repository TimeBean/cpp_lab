#include <cmath>
#include "../../include/laboratory/WhileBasedFunction.h"
#include "../../include/common/Result.h"

namespace Laboratory {
    std::vector<Common::Result<double> > WhileBasedFunction::Compute() const {
        auto result = std::vector<Laboratory::Common::Result<double> >();

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
