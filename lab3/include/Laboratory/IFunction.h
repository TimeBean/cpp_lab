#pragma once
#include <string>
#include <vector>

#include "utils/Result.h"

namespace Laboratory {
    class IFunction {
    public:
        virtual ~IFunction() = default;

        [[nodiscard]] virtual std::string GetFunctionName() const noexcept = 0;
        [[nodiscard]] virtual std::vector<Result<double>> Execute() const = 0 ;
    };
}
