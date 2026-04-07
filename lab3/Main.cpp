#include <iomanip>
#include <iostream>
#include <memory>
#include <vector>

#include "include/laboratory/WhileBasedFunction.cpp.h"
#include "include/laboratory/DoWhileBasedFunction.cpp.h"
#include "include/laboratory/ForBasedFunction.h"

constexpr size_t LEFT_OFFSET = 3;

#ifdef _WIN32
#include <windows.h>
#endif

void Clear() {
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD count;
    DWORD cellCount;
    COORD homeCoords = {0, 0};

    if (hConsole == INVALID_HANDLE_VALUE) return;

    if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) return;
    cellCount = csbi.dwSize.X * csbi.dwSize.Y;

    FillConsoleOutputCharacter(hConsole, ' ', cellCount, homeCoords, &count);
    FillConsoleOutputAttribute(hConsole, csbi.wAttributes, cellCount, homeCoords, &count);
    SetConsoleCursorPosition(hConsole, homeCoords);
#else
    std::cout << "\033[2J\033[H";
#endif
}

void WaitForEnter() {
    std::cout << "Нажмите Enter, чтобы продолжить..." << std::flush;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

void DisplayResult(const std::vector<Laboratory::Common::Result<double> > &results) {
    std::cout << std::string(LEFT_OFFSET, ' ') << "(x, y)\n";
    for (const auto &result: results) {
        std::cout << std::string(LEFT_OFFSET, ' ') << '(' << result.Input << ", " << result.Output << ")\n";
    }

    WaitForEnter();
    Clear();
}

void DisplayMenu(const std::vector<std::unique_ptr<Laboratory::Functions::IFunction> > &functions) {
    std::cout << "Лабораторная работа 3.\n\nДоступные варианты:\n";
    for (size_t i = 0; i < functions.size(); ++i) {
        std::cout << "   (" << functions[i]->GetKey() << ") "
                << i + 1 << ". " << functions[i]->GetName() << "\n";
    }
    std::cout << "   (q) 0. Выход\n";
}

int main() {
    using namespace Laboratory::Functions;
    std::vector<std::unique_ptr<IFunction> > functions;
    functions.push_back(std::make_unique<Laboratory::WhileBasedFunction>());
    functions.push_back(std::make_unique<Laboratory::DoWhileBasedFunction>());
    functions.push_back(std::make_unique<Laboratory::ForBasedFunction>());

    Clear();
    while (true) {
        DisplayMenu(functions);

        std::string input;
        std::cin >> input;

        if (input == "0" || input == "q") {
            break;
        }

        const IFunction *selected = nullptr;
        for (size_t i = 0; i < functions.size(); ++i) {
            if (input == functions[i]->GetKey() || input == std::to_string(i + 1)) {
                selected = functions[i].get();
                break;
            }
        }

        if (!selected) {
            std::cout << "Такого варианта нет.\n";
            continue;
        }

        Clear();
        std::cout << selected->GetName() << '\n';
        auto results = selected->Execute();

        DisplayResult(results);
    }

    return 0;
}
