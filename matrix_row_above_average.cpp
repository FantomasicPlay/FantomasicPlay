#include <iostream>
#include <vector>
#include <random>
using namespace std;

vector<vector<int>> generateRandomMatrix(int minRows = 1, int maxRows = 10,
                                          int minCols = 1, int maxCols = 10,
                                          int minVal = -50, int maxVal = 50) {
    static mt19937 rng(random_device{}());
    uniform_int_distribution<int> rowsDist(minRows, maxRows);
    uniform_int_distribution<int> colsDist(minCols, maxCols);
    uniform_int_distribution<int> valDist(minVal, maxVal);

    int rows = rowsDist(rng);
    int cols = colsDist(rng);

    vector<vector<int>> matrix(rows, vector<int>(cols));
    for (auto& row : matrix) {
        for (int& x : row) {
            x = valDist(rng);
        }
    }
    return matrix;
}

double averageOfMatrix(const vector<vector<int>>& matrix) {
    long long sum = 0;
    int count = 0;
    for (const auto& row : matrix) {
        for (int x : row) {
            sum += x;
            ++count;
        }
    }
    return count == 0 ? 0.0 : static_cast<double>(sum) / count;
}

bool hasRowAboveAverage(const vector<vector<int>>& matrix, double average) {
    for (const auto& row : matrix) {
        bool allAbove = true;
        for (int x : row) {
            if (x <= average) {
                allAbove = false;
                break;
            }
        }
        if (allAbove) {
            return true;
        }
    }
    return false;
}

int main() {
    vector<vector<int>> matrix = generateRandomMatrix();

    cout << "Сгенерированная матрица (" << matrix.size() << " x "
         << matrix[0].size() << "):\n";
    for (const auto& row : matrix) {
        for (int x : row) {
            cout << x << '\t';
        }
        cout << '\n';
    }

    double average = averageOfMatrix(matrix);
    cout << "Среднее арифметическое всех элементов: " << average << '\n';

    if (hasRowAboveAverage(matrix, average)) {
        cout << "В матрице есть строка, все элементы которой больше среднего\n";
    } else {
        cout << "В матрице нет строки, все элементы которой больше среднего\n";
    }

    return 0;
}
