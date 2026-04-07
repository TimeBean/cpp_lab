#pragma once

namespace Laboratory::Common {
    template<typename T>

    struct Result {
        Result(T input, T output) {
            Input = input;
            Output = output;
        }

        T Input;
        T Output;
    };
} // namespace Common
