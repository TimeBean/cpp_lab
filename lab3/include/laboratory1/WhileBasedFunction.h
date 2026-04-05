#pragma once
#include "../common/Result.h"
#include "../common/IFunction.h"

namespace Laboratory::FirstLaboratory {
    class WhileBasedFunction : public Common::IFunction {
    public:
        std::vector<Common::Result<double> > Compute() override;

        WhileBasedFunction(const double a, const double b, const double step) {
            A = a;
            B = b;
            STEP = step;
        }

        ~WhileBasedFunction() override = default;

    private:
        double A;
        double B;
        double STEP;
    };
}
