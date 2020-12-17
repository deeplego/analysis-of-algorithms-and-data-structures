#pragma once

#include <vector>
#include <iostream>

#include "utils.h"

std::vector<int> quicksort(std::vector<int> vector);
void innerQuicksort(std::vector<int> &vector, int leftIdx, int rightIdx);
std::tuple<std::vector<int>, int, int, int> quicksortOperationsCounter(std::vector<int> vector);
void innerQuicksortOperationsCounter(
    std::vector<int> &vector, int leftIdx, int rightIdx,
    int &numPartitions, int &numComparisons, int &numSwaps
);