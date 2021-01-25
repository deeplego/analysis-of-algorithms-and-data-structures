#include <cassert>

#include "../src/utils.h"

void testArraysAreEqualNotReally() {
    std::vector<int> unordered{5, 4, 1, 9, 8, 7, 6, 3, 2, 0};
    std::vector<int> ordered{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    assert(arraysAreEqual(unordered, ordered) == false);
}

void testArraysAreEqualActually() {
    std::vector<int> unorderedOne{5, 4, 1, 9, 8, 7, 6, 3, 2, 0};
    std::vector<int> unorderedTwo{5, 4, 1, 9, 8, 7, 6, 3, 2, 0};
    assert(arraysAreEqual(unorderedOne, unorderedTwo) == true);
}

void testGetAllPermutations2() {
    std::vector<int> vector{0, 1};
    std::vector<std::vector<int>> expected{
        {0, 1},
        {1, 0}
    };
    std::vector<std::vector<int>> actual = getAllPermutations(vector);
    for (int i = 0; i < static_cast<int>(expected.size()); ++i) {
        assert(arraysAreEqual(actual[i], expected[i]));
    }
}

void testGetAllPermutations3() {
    std::vector<int> vector{1, 2, 0};
    std::vector<std::vector<int>> expected{
        {0, 1, 2},
        {0, 2, 1},
        {1, 0, 2},
        {1, 2, 0},
        {2, 0, 1},
        {2, 1, 0}
    };
    std::vector<std::vector<int>> actual = getAllPermutations(vector);
    for (int i = 0; i < static_cast<int>(expected.size()); ++i) {
        assert(arraysAreEqual(actual[i], expected[i]));
    }
}

int main() {
    testArraysAreEqualNotReally();
    testArraysAreEqualActually();
    testGetAllPermutations2();
    testGetAllPermutations3();
    std::cout << "All tests passed!\n";
    exit(0);
}
