#include "quicksort.h"

std::vector<int> quicksort(std::vector<int> vector) {
    int vectorLength = vector.size();
    auto it = vector.begin();
    vector.insert(it, std::numeric_limits<int>::min());
    vector.push_back(std::numeric_limits<int>::max());
    innerQuicksort(vector, 1, vectorLength);
    std::vector<int> resultVector = std::vector<int>(
        vector.begin() + 1,
        vector.end() - 1
    );
    return resultVector;
}

void innerQuicksort(std::vector<int> &vector, int leftIdx, int rightIdx) {
    int pivot;
    int temporary;
    int i;
    int j;
    if (leftIdx <= rightIdx) {
        pivot = vector[rightIdx];
        i = leftIdx - 1;
        j = rightIdx;
        while (i <= j) {
            ++i;
            while(vector[i] < pivot) {
                ++i;
            }
            --j;
            while((leftIdx <= j) && (vector[j] > pivot)) {
                --j;
            }
            if (i < j) {
                temporary = vector[i];
                vector[i] = vector[j];
                vector[j] = temporary;
            }
        }
            temporary = vector[i];
            vector[i] = pivot;
            vector[rightIdx] = temporary;
        innerQuicksort(vector, leftIdx, i - 1);
        innerQuicksort(vector, i + 1, rightIdx);
    }
}

std::tuple<std::vector<int>, int, int, int> quicksortOperationsCounter(
    std::vector<int> vector
) {
    int vectorLength = vector.size();
    auto it = vector.begin();
    vector.insert(it, std::numeric_limits<int>::min());
    vector.push_back(std::numeric_limits<int>::max());
    int numPartitions = 0;
    int numComparisons = 0;
    int numSwaps = 0;
    innerQuicksortOperationsCounter(
        vector, 1, vectorLength,
        numPartitions, numComparisons, numSwaps
    );
    std::vector<int> resultVector = std::vector<int>(
        vector.begin() + 1,
        vector.end() - 1
    );
    return std::make_tuple(resultVector, numPartitions, numComparisons, numSwaps);
}

void innerQuicksortOperationsCounter(
    std::vector<int> &vector, int leftIdx, int rightIdx,
    int &numPartitions, int &numComparisons, int &numSwaps
) {
    int pivot;
    int temporary;
    int i;
    int j;
    if (leftIdx <= rightIdx) {
        ++numPartitions;
        pivot = vector[rightIdx];
        i = leftIdx - 1;
        j = rightIdx;
        while (i < j) {
            ++i;
            ++numComparisons;
            while(vector[i] < pivot) {
                ++i;
                ++numComparisons;
            }
            --j;
            ++numComparisons;
            while((leftIdx <= j) && (vector[j] > pivot)) {
                --j;
                ++numComparisons;
            }
            if (i < j) {
                temporary = vector[i];
                vector[i] = vector[j];
                vector[j] = temporary;
                ++numSwaps;
            }
        }
            temporary = vector[i];
            vector[i] = pivot;
            vector[rightIdx] = temporary;
        innerQuicksortOperationsCounter(
            vector, leftIdx, i - 1,
            numPartitions, numComparisons, numSwaps
        );
        innerQuicksortOperationsCounter(
            vector, i + 1, rightIdx,
            numPartitions, numComparisons, numSwaps
        );
    }
}
