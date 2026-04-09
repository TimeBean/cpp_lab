#pragma once
#include "IFunction.h"

namespace Laboratory {
    class ForBasedFunction final : public IFunction {
    public:
        [[nodiscard]] std::string GetFunctionName() const noexcept override {
            return "Exercise 3.3 (using `for`)";
        }

        [[nodiscard]] std::vector<Result<double> > Execute() const override;

    private:
        [[nodiscard]] static std::vector<Result<double> > Compute(double input);
    };
}
