#include <iostream>
#include <vector>
#include <random>
#include <optional>

std::vector<int> generateRandomArray(int minLen = 1, int maxLen = 20,
                                      int minVal = -100, int maxVal = 100) {
    static std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> lenDist(minLen, maxLen);
    std::uniform_int_distribution<int> valDist(minVal, maxVal);

    int length = lenDist(rng);
    std::vector<int> arr(length);
    for (int& x : arr) {
        x = valDist(rng);
    }
    return arr;
}

std::optional<int> maxDivisibleBy5(const std::vector<int>& arr) {
    std::optional<int> result;
    for (int x : arr) {
        if (x % 5 == 0) {
            if (!result || x > *result) {
                result = x;
            }
        }
    }
    return result;
}

int main() {
    std::vector<int> arr = generateRandomArray();

    std::cout << "Сгенерированный массив (" << arr.size() << " элементов): ";
    for (int x : arr) {
        std::cout << x << ' ';
    }
    std::cout << '\n';

    auto result = maxDivisibleBy5(arr);
    if (result) {
        std::cout << "Максимальный элемент, кратный 5: " << *result << '\n';
    } else {
        std::cout << "В массиве нет элементов, кратных 5\n";
    }

    return 0;
}
