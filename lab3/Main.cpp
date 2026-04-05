#include <iomanip>
#include <iostream>
#include <vector>

#include "include/common/FunctionType.h"
#include "include/laboratory/WhileBasedFunction.h"
#include "include/laboratory/DoWhileBasedFunction.h"
#include "include/laboratory/ForBasedFunction.h"

constexpr double FIRST_A = -3;
constexpr double SECOND_A = 2.5;
constexpr double B = 3;
constexpr double STEP = 0.3;
constexpr double DELTA_T = 0.5;

constexpr size_t LEFT_OFFSET = 3;

void Clear() {
    std::cout << "\033[2J\033[H";
}

void DisplayResult(const std::vector<Laboratory::Common::Result<double> >& results) {
    std::cout << std::string(LEFT_OFFSET, ' ') << "(x, y)\n";
    for (const auto &result: results) {
        std::cout << std::string(LEFT_OFFSET, ' ') << '(' << result.Input << ", " << result.Output << ")\n";
    }
}

void WaitForAnyUserInput() {
    std::cout << "Нажмите Enter, чтобы продолжить...";
    std::string dummy;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, dummy);
}

void DisplayFunction(const Laboratory::Common::FunctionType functionType) {
    using namespace Laboratory;
    using Common::Result;

    Clear();

    std::vector<Result<double> > results;
    if (functionType == Common::ForBased) {
        std::cout << "Выбран алгоритм на основе for.\n";
        std::cout << "Введите значение x: ";
        double x;
        if (!(std::cin >> x)) {
            std::cerr << "Введенная строка некорректна. Ожидалось число.\n";
            throw std::runtime_error("Некорректный ввод числа.");
        }
        std::cout << "\n";
        results = ForBasedFunction::Compute(x);
    } else if (functionType == Common::DoWhileBased) {
        std::cout << "Выбран алгоритм на основе do...while.\n\n";
        results = WhileBasedFunction{FIRST_A, B, STEP}.Compute();
    } else if (functionType == Common::WhileBased) {
        std::cout << "Выбран алгоритм на основе while.\n\n";
        results = DoWhileBasedFunction{SECOND_A, DELTA_T}.Compute();
    }

    DisplayResult(results);
    std::cout << '\n';
    WaitForAnyUserInput();
    Clear();
}

int main() {
    Clear();

    while (true) {
        std::cout << "Лабораторная работа 3.\n\n"
                << "   Доступные варианты:\n"
                << "      (w) 1. Задание 3.1 (На основе while)\n"
                << "      (d) 2. Задание 3.2 (На основе do...while)\n"
                << "      (f) 3. Задание 3.3 (На основе for)\n"
                << "      (q) 0. Выход\n";

        std::cout << "\nВыберите пункт: ";
        std::string userInput;
        std::cin >> userInput;

        if (userInput == "1" || userInput == "w") {
            DisplayFunction(Laboratory::Common::WhileBased);
        } else if (userInput == "2" || userInput == "d") {
            DisplayFunction(Laboratory::Common::DoWhileBased);
        } else if (userInput == "3" || userInput == "f") {
            DisplayFunction(Laboratory::Common::ForBased);
        } else if (userInput == "0" || userInput == "q") {
            break;
        } else {
            std::cout << "Такого варианта нет.\n";
            WaitForAnyUserInput();
        }

        Clear();
    }

    return 0;
}
