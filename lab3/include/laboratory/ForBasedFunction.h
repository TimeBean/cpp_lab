#pragma once
#include "IFunction.h"

namespace Laboratory {
    class ForBasedFunction final : public Functions::IFunction {
    public:
        [[nodiscard]] std::string GetName() const override {
            return "Задание 3.3 (на основе for)";
        }

        [[nodiscard]] std::string GetKey() const override {
            return "f";
        }

        [[nodiscard]] std::vector<Common::Result<double> > Execute() const override;

    private:
        [[nodiscard]] static std::vector<Common::Result<double> > Compute(double input);
    };
}
