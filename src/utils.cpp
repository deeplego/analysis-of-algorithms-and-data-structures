#include "utils.h"

void printVector(std::vector<int> vector) {
    int vectorLength = vector.size();
    if (vector.size() != 0) {
        std::cout << "[ ";
        for (int i = 0; i < vectorLength - 1; ++i) {
            std::cout << vector[i] << ", ";
        }
        std::cout << vector[vectorLength - 1] << " ]\n";
    }
}

void printMatrix(std::vector<std::vector<int>> matrix) {
    int outerDimension = matrix.size();
    std::cout << "[\n";
    for (int i = 0; i < outerDimension; ++i) {
        std::cout << "  ";
        printVector(matrix[i]);
    }
    std::cout << "]\n";
}

bool arraysAreEqual(std::vector<int> &a, std::vector<int> &b) {
    int aLength = a.size();
    int bLength = b.size();
    if (aLength != bLength) { return false; }
    for (int i = 0; i < bLength; ++i) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

std::vector<std::vector<int>> getAllPermutations(std::vector<int> &vector) {
    std::vector<int> sortedVector = quicksort(vector);
    std::vector<std::vector<int>> allPermutations;
    do {
        allPermutations.push_back(sortedVector);
    } while (std::next_permutation(sortedVector.begin(), sortedVector.end()));
    return allPermutations;
}

std::int_fast64_t powint(int base, int exp) {
    std::int_fast64_t result{ 1 };
    while (exp) {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        base *= base;
    } 
    return result;
}

namespace seedNamespace {
    std::mt19937 seed{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
}

int getRandomNumber(int min, int max) {
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(seedNamespace::seed);
}

std::vector<int> getRandomVector(int length) {
    std::vector<int> randomVector(length);
    std::generate(randomVector.begin(), randomVector.end(), [&]() { return getRandomNumber(); });
    return randomVector;
}

double vectorMean(std::vector<int> &vector) {
    double result = 0;
    for (auto &it: vector) { result += it; }
    return static_cast<double>(result) / vector.size();
}

double harmonic(int n) {
    double result = 0;
    for (double i = 1; i < n + 1; ++i) {
        result += 1 / i;
    }
    return result;
}

void swap(std::vector<int> &vector, int idxA, int idxB) {
    int temporary = vector[idxA];
    vector[idxA] = vector[idxB];
    vector[idxB] = temporary;
}

std::vector<int> getRandomPermutation(std::vector<int> &vector) {
    int vectorLength = vector.size();
    std::vector<int> orderedVector = quicksort(vector);
    std::vector<int> randomPermutation = vector;
    for (int idx = vectorLength - 1; idx > 0; --idx) {
        int randomIdx = getRandomNumber(0, idx - 1);
        swap(randomPermutation, idx, randomIdx);
    }
    return randomPermutation;
}
