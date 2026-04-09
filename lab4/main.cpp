#include <array>
#include <iomanip>
#include <iostream>
#include <random>

constexpr int ELEMENTS_COUNT_K = 70;
constexpr int ELEMENT_MINIMUM_Z1 = -40;
constexpr int ELEMENT_MAXIMUM_Z2 = 60;
constexpr int ROWS_N = 10;
constexpr int COLUMNS_M = 7;

int main() {
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution dist(ELEMENT_MINIMUM_Z1, ELEMENT_MAXIMUM_Z2);

    std::cout << "Here is an array (represented as a matrix):\n";

    std::array<int, ELEMENTS_COUNT_K> b{};
    int counter = 0;
    for (int& element : b) {
        element = dist(rng);
        std::cout << std::setw(3) << element << ' ';

        counter++;
        if (counter == ROWS_N) {
            std::cout << '\n';
            counter = 0;
        }
    }

    int count = 0;
    int sum = 0;
    for (const int& element: b) {
        if (!(element < -10 || element > 30)) {
            continue;
        }

        count += 1;
        sum += element;
    }

    std::cout << "\nData for elements less than -10 or greater than 30:\n";
    std::cout << "Quantity: " << count << '\n';
    std::cout << "Sum: " << sum << '\n';

    return 0;
}
