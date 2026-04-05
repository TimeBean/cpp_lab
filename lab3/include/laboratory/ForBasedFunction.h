#pragma once
#include <vector>

#include "../common/Result.h"

namespace Laboratory {
    class ForBasedFunction {
    public:
        static std::vector<Common::Result<double> > Compute(double input);

        ~ForBasedFunction() = default;
    };
}
