#pragma once
#include "IFunction.h"

namespace Laboratory {
    class DoWhileBasedFunction final : public IFunction {
    public:
        [[nodiscard]] std::string GetFunctionName() const noexcept override {
            return "Exercise 3.2 (using the do...while loop)";
        }

        [[nodiscard]] std::vector<Result<double> > Execute() const noexcept override;

    private:
        static constexpr double A = 2.5;
        static constexpr double DeltaT = 0.5;

        [[nodiscard]] static std::vector<Result<double> > Compute();
    };
}
