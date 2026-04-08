#pragma once
#include "IFunction.h"

namespace Laboratory {
    class DoWhileBasedFunction final : public IFunction {
    public:
        [[nodiscard]] std::string GetFunctionName() const noexcept override {
            return "Задание 3.2 (на основе do...while)";
        }

        [[nodiscard]] std::vector<Result<double> > Execute() const noexcept override;

    private:
        static constexpr double kA = 2.5;
        static constexpr double kDeltaT = 0.5;

        [[nodiscard]] static std::vector<Result<double> > Compute();
    };
}
