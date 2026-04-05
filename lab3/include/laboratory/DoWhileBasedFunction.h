#pragma once
#include <vector>

#include "../common/Result.h"


namespace Laboratory {
    class DoWhileBasedFunction {
    public:
        [[nodiscard]] std::vector<Common::Result<double> > Compute() const;

        DoWhileBasedFunction(const double a, const double deltaT) {
            A = a;
            DeltaT = deltaT;
        }

        ~DoWhileBasedFunction() = default;

    private:
        double A;
        double DeltaT;
    };
}
