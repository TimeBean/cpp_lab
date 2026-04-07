#pragma once
#include <string>
#include <vector>
#include "../common/Result.h"

namespace Laboratory::Functions {
    class IFunction {
    public:
        virtual ~IFunction() = default;

        /// Название алгоритма для отображения в меню
        /// @return Строку с именем функции, для вывода пользователю
        [[nodiscard]] virtual std::string GetName() const = 0;

        /// Ключ для выбора из меню
        /// @return Ключ вида: "a"
        [[nodiscard]] virtual std::string GetKey() const = 0;

        /// Вычислить результат
        /// @return Вектор результатов, каждый из которых содержит входное и вычисленное значение
        [[nodiscard]] virtual std::vector<Common::Result<double> > Execute() const = 0;
    };
}