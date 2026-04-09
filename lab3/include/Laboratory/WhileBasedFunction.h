#pragma once
#include "IFunction.h"

namespace Laboratory {
    class WhileBasedFunction final : public IFunction {
    public:
        [[nodiscard]] std::string GetFunctionName() const noexcept override {
            return "Exercise 3.1 (using a while loop)";
        }

        [[nodiscard]] std::vector<Result<double> > Execute() const noexcept override;

    private:
        static constexpr double A = -3.0;
        static constexpr double B = 3.0;
        static constexpr double Step = 0.3;

        [[nodiscard]] static std::vector<Result<double> > Compute();
    };
}
