#pragma once
#include "IFunction.h"

namespace Laboratory {
    class WhileBasedFunction final : public Functions::IFunction {
    public:
        [[nodiscard]] std::string GetName() const override {
            return "Задание 3.1 (на основе while)";
        }

        [[nodiscard]] std::string GetKey() const override {
            return "w";
        }

        [[nodiscard]] std::vector<Common::Result<double> > Execute() const override;

    private:
        static constexpr double kA = -3.0;
        static constexpr double kB = 3.0;
        static constexpr double kStep = 0.3;

        static std::vector<Common::Result<double> > Compute();

    };
}
