#pragma once

namespace Laboratory {
    template<typename T>

    struct Result {
        Result(T input, T output) {
            Input = input;
            Output = output;
        }

        T Input;
        T Output;
    };
}
