#pragma once
#include "IFunction.h"

namespace Laboratory {
    class WhileBasedFunction final : public IFunction {
    public:
        [[nodiscard]] std::string GetFunctionName() const noexcept override {
            return "Задание 3.1 (на основе while)";
        }

        [[nodiscard]] std::vector<Result<double> > Execute() const noexcept override;

    private:
        static constexpr double kA = -3.0;
        static constexpr double kB = 3.0;
        static constexpr double kStep = 0.3;

        [[nodiscard]] static std::vector<Result<double> > Compute();
    };
}
