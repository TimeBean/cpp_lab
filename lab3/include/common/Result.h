#pragma once

namespace Laboratory::Common {
    template<typename T>

    class Result {
    public:
        Result(T input, T output) {
            Input = input;
            Output = output;
        };

        T Input;
        T Output;
    };
} // namespace Common
