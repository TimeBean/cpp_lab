#include <limits>
#include <memory>

#include "../include/Laboratory/IFunction.h"
#include "../include/Laboratory/WhileBasedFunction.h"
#include "../include/Laboratory/DoWhileBasedFunction.h"
#include "../include/Laboratory/ForBasedFunction.h"
#include "../include/Laboratory/utils/CrossPlatformTerminalCleaner.h"

constexpr int LEFT_OFFSET = 3;

void WaitForEnter() {
    std::cout << "Нажмите Enter, чтобы продолжить..." << std::flush;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

void DisplayResult(const std::vector<Laboratory::Result<double> > &results) {
    std::cout << std::string(LEFT_OFFSET, ' ') << "(x, y)\n";

    for (const auto &result: results) {
        std::cout << std::string(LEFT_OFFSET, ' ') << '(' << result.Input << ", " << result.Output << ")\n";
    }
}

void DisplayMenu(const std::vector<std::unique_ptr<Laboratory::IFunction> > &functions) {
    std::cout << "Лабораторная работа 3.\n\nДоступные варианты:\n";

    const auto offset = std::string(LEFT_OFFSET, ' ');

    for (size_t i = 0; i < functions.size(); ++i) {
        std::cout << offset << i + 1 << ". " << functions[i]->GetFunctionName() << "\n";
    }
    std::cout << offset << "0. Выход\n";
}


int main() {
    using namespace Laboratory;
    using std::vector, std::unique_ptr;

    vector<unique_ptr<IFunction>> functions;
    functions.push_back(std::make_unique<WhileBasedFunction>());
    functions.push_back(std::make_unique<DoWhileBasedFunction>());
    functions.push_back(std::make_unique<ForBasedFunction>());

    CrossPlatformTerminalCleaner::Clear();
    while (true) {
        DisplayMenu(functions);

        std::cout << "\nВыберите вариант: ";

        std::string input;
        std::cin >> input;

        if (input == "0" || input == "q") {
            break;
        }

        const IFunction *selected = nullptr;
        for (size_t i = 0; i < functions.size(); ++i) {
            if (input == std::to_string(i + 1)) {
                selected = functions[i].get();
                break;
            }
        }

        if (!selected) {
            std::cout << "Такого варианта нет.\n";
            continue;
        }

        CrossPlatformTerminalCleaner::Clear();
        std::cout << selected->GetFunctionName() << '\n';
        auto results = selected->Execute();

        DisplayResult(results);
        WaitForEnter();
        CrossPlatformTerminalCleaner::Clear();
    }

    return 0;
}
