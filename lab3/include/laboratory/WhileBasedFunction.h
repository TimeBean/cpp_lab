#pragma once
#include <vector>

#include "../common/Result.h"

namespace Laboratory {
    class WhileBasedFunction {
    public:
        [[nodiscard]] std::vector<Common::Result<double> > Compute() const;

        WhileBasedFunction(const double a, const double b, const double step) {
            A = a;
            B = b;
            STEP = step;
        }

        ~WhileBasedFunction() = default;

    private:
        double A;
        double B;
        double STEP;
    };
}