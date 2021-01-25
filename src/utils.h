#pragma once

#include <vector>
#include <iostream>
#include <algorithm>
#include <random>
#include <cmath> // for log2
#include <cstdint> // for std::int_fast64_t
#include <random> // PRNG
#include <ctime> // PRNG
#include <tuple>

#include "quicksort.h"

void printVector(std::vector<int> vector);
void printMatrix(std::vector<std::vector<int>> matrix);
bool arraysAreEqual(std::vector<int> &a, std::vector<int> &b);
std::vector<std::vector<int>> getAllPermutations(std::vector<int> &vector);
std::int_fast64_t powint(int base, int exp);
int getRandomNumber(int min = 0, int max = 1000);
std::vector<int> getRandomVector(int length);
double vectorMean(std::vector<int> &vector);
double harmonic(int n);
std::vector<int> getRandomPermutation(std::vector<int> &vector);
void swap(std::vector<int> &vector, int idxA, int idxB);
