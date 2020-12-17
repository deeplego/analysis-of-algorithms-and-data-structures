#include <cassert>
#include <utility>

#include "../src/mergesort.h"
#include "../src/utils.h"

void testMergesort1() {
    std::vector<int> unordered{1};
    std::vector<int> ordered{1};
    std::vector<int> *expected = &ordered;
    std::vector<int> actual = mergesort(unordered);
    assert(arraysAreEqual(actual, *expected));
}

void testMergesort2() {
    std::vector<int> unordered{5, 1};
    std::vector<int> ordered{1, 5};
    std::vector<int> *expected = &ordered;
    std::vector<int> actual = mergesort(unordered);
    assert(arraysAreEqual(actual, *expected));
}

void testMergesort10() {
    std::vector<int> unordered{5, 4, 1, 9, 8, 7, 6, 3, 2, 0};
    std::vector<int> ordered{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> *expected = &ordered;
    std::vector<int> actual = mergesort(unordered);
    assert(arraysAreEqual(actual, *expected));
}

void testMergesortComparisonCounter1() {
    std::vector<int> unordered{1};
    std::vector<int> expectedFirst{1};
    int expectedSecond = 0;
    std::pair<std::vector<int>, int> actual = mergesortComparisonCounter(unordered);
    assert(arraysAreEqual(actual.first, expectedFirst));
    assert(actual.second == expectedSecond);
}

void testMergesortComparisonCounter2() {
    std::vector<int> unordered{5, 4};
    std::vector<int> expectedFirst{4, 5};
    int expectedSecond = 2;
    std::pair<std::vector<int>, int> actual = mergesortComparisonCounter(unordered);
    assert(arraysAreEqual(actual.first, expectedFirst));
    assert(actual.second == expectedSecond);
}



int main() {
    testMergesort1();
    testMergesort2();
    testMergesort10();
    testMergesortComparisonCounter1();
    testMergesortComparisonCounter2();
    std::cout << "All tests passed!\n";
    exit(0);
}

