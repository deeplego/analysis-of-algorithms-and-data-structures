#include <limits>

#include "mergesort.h"
#include "utils.h"

std::vector<int> mergesort(std::vector<int> vector) {
    int vectorLength = vector.size();
    std::vector<int> aSupport(vectorLength / 2 + 2, 0);
    std::vector<int> bSupport(vectorLength / 2 + 2, 0);
    innerMergesort(vector, aSupport, bSupport, 0, vectorLength - 1);
    return vector;
}

void innerMergesort(
    std::vector<int> &vector,
    std::vector<int> &aSupport,
    std::vector<int> &bSupport,
    int leftIdx,
    int rightIdx
) {
    if ((rightIdx - leftIdx) > 0) {
        int middleIdx = (leftIdx + rightIdx) / 2;
        innerMergesort(vector, aSupport, bSupport, leftIdx, middleIdx);
        innerMergesort(vector, aSupport, bSupport, middleIdx + 1, rightIdx);
        for (int i = 0; i < middleIdx - leftIdx + 1; ++i) {
            aSupport[i] = vector[leftIdx + i];
        }
        for (int i = middleIdx + 1; i < rightIdx + 1; ++i) {
            bSupport[i - middleIdx - 1] = vector[i];
        }
        aSupport[middleIdx - leftIdx + 1] = std::numeric_limits<int>::max();
        bSupport[rightIdx - middleIdx] = std::numeric_limits<int>::max();
        int i = 0;
        int j = 0;
        for (int k = leftIdx; k < rightIdx + 1; ++k) {
            if (aSupport[i] < bSupport[j]) {
                vector[k] = aSupport[i];
                ++i;
            } else {
                vector[k] = bSupport[j];
                ++j;
            }
        }
    }
}

std::pair<std::vector<int>, int> mergesortComparisonCounter(std::vector<int> vector) {
    int vectorLength = vector.size();
    std::vector<int> aSupport(vectorLength / 2 + 2, 0);
    std::vector<int> bSupport(vectorLength / 2 + 2, 0);
    int counter = 0;
    innerMergesortComparisonCounter(vector, aSupport, bSupport, 0, vectorLength - 1, counter);
    return std::make_pair(vector, counter);
}

void innerMergesortComparisonCounter(
    std::vector<int> &vector,
    std::vector<int> &aSupport,
    std::vector<int> &bSupport,
    int leftIdx,
    int rightIdx,
    int &counter
) {
    if ((rightIdx - leftIdx) > 0) {
        int middleIdx = (leftIdx + rightIdx) / 2;
        innerMergesortComparisonCounter(vector, aSupport, bSupport, leftIdx, middleIdx, counter);
        innerMergesortComparisonCounter(vector, aSupport, bSupport, middleIdx + 1, rightIdx, counter);
        for (int i = 0; i < middleIdx - leftIdx + 1; ++i) {
            aSupport[i] = vector[leftIdx + i];
        }
        for (int i = middleIdx + 1; i < rightIdx + 1; ++i) {
            bSupport[i - middleIdx - 1] = vector[i];
        }
        aSupport[middleIdx - leftIdx + 1] = std::numeric_limits<int>::max();
        bSupport[rightIdx - middleIdx] = std::numeric_limits<int>::max();
        int i = 0;
        int j = 0;
        for (int k = leftIdx; k < rightIdx + 1; ++k) {
            ++counter;
            if (aSupport[i] < bSupport[j]) {
                vector[k] = aSupport[i];
                ++i;
            } else {
                vector[k] = bSupport[j];
                ++j;
            }
        }
    }
}
