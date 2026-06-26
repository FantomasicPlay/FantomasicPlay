#include <iostream>
#include <vector>
#include <random>
using namespace std;

vector<int> generateRandomArray(int minLen = 1, int maxLen = 20,
                                 int minVal = -100, int maxVal = 100) {
    static mt19937 rng(random_device{}());
    uniform_int_distribution<int> lenDist(minLen, maxLen);
    uniform_int_distribution<int> valDist(minVal, maxVal);

    int length = lenDist(rng);
    vector<int> arr(length);
    for (int& x : arr) {
        x = valDist(rng);
    }
    return arr;
}

bool maxDivisibleBy5(const vector<int>& arr, int& result) {
    bool found = false;
    for (int x : arr) {
        if (x % 5 == 0) {
            if (!found || x > result) {
                result = x;
                found = true;
            }
        }
    }
    return found;
}

int main() {
    vector<int> arr = generateRandomArray();

    cout << "Сгенерированный массив (" << arr.size() << " элементов): ";
    for (int x : arr) {
        cout << x << ' ';
    }
    cout << '\n';

    int result;
    if (maxDivisibleBy5(arr, result)) {
        cout << "Максимальный элемент, кратный 5: " << result << '\n';
    } else {
        cout << "В массиве нет элементов, кратных 5\n";
    }

    return 0;
}
