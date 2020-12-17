#pragma once

#include <vector>
#include <utility>

std::vector<int> mergesort(std::vector<int> vector);
void innerMergesort(
    std::vector<int> &vector,
    std::vector<int> &aSupport,
    std::vector<int> &bSupport,
    int leftIdx,
    int rightIdx
);

std::pair<std::vector<int>, int> mergesortComparisonCounter(std::vector<int> vector);
void innerMergesortComparisonCounter(
    std::vector<int> &vector,
    std::vector<int> &aSupport,
    std::vector<int> &bSupport,
    int leftIdx,
    int rightIdx,
    int &counter
);
