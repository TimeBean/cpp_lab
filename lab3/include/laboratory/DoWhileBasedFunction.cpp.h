#pragma once
#include "IFunction.h"

namespace Laboratory {
    class DoWhileBasedFunction final : public Functions::IFunction {
    public:
        [[nodiscard]] std::string GetName() const override {
            return "Задание 3.2 (на основе do...while)";
        }

        [[nodiscard]] std::string GetKey() const override {
            return "d";
        }

        [[nodiscard]] std::vector<Common::Result<double> > Execute() const override;

    private:
        static constexpr double kA = -3.0;
        static constexpr double kB = 3.0;
        static constexpr double kDeltaT = 0.3;

        [[nodiscard]] static std::vector<Common::Result<double>> Compute();
    };
}
