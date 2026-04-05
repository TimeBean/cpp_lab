#pragma once
#include <span>
#include <vector>

#include "Result.h"

namespace Laboratory::Common {
    class IFunction {
    public:
        virtual std::vector<Result<double>> Compute() = 0;

        virtual ~IFunction() = default;
    };
} // namespace common