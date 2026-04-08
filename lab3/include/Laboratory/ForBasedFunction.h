#pragma once
#include "IFunction.h"

namespace Laboratory {
    class ForBasedFunction final : public IFunction {
    public:
        [[nodiscard]] std::string GetFunctionName() const noexcept override {
            return "Задание 3.3 (на основе for)";
        }

        [[nodiscard]] std::vector<Result<double> > Execute() const override;

    private:
        [[nodiscard]] static std::vector<Result<double> > Compute(double input);
    };
}
