#include <cassert>
#include <utility>

#include "../src/quicksort.h"
#include "../src/utils.h"

void testQuicksort1() {
    std::vector<int> unordered{1};
    std::vector<int> ordered{1};
    std::vector<int> *expected = &ordered;
    std::vector<int> actual = quicksort(unordered);
    assert(arraysAreEqual(actual, *expected));
}

void testQuicksort2() {
    std::vector<int> unordered{5, 1};
    std::vector<int> ordered{1, 5};
    std::vector<int> *expected = &ordered;
    std::vector<int> actual = quicksort(unordered);
    assert(arraysAreEqual(actual, *expected));
}

void testQuicksort10() {
    std::vector<int> unordered{5, 4, 1, 9, 8, 7, 6, 3, 2, 0};
    std::vector<int> ordered{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> *expected = &ordered;
    std::vector<int> actual = quicksort(unordered);
    assert(arraysAreEqual(actual, *expected));
}

void testQuicksortOperationsCounterNumPartitionsFrom1To5() {
    int maxLength = 5;
    for (int n = 1; n < maxLength + 1; ++n) {
        std::vector<int> randomVector = getRandomVector(n);
        std::vector<int> expectedOrdered(randomVector);
        std::sort(expectedOrdered.begin(), expectedOrdered.end());
        int expectedNumPartitions = n;
        std::tuple<std::vector<int>, int, int, int> actual = quicksortOperationsCounter(randomVector);
        assert(arraysAreEqual(std::get<0>(actual), expectedOrdered));
        assert(std::get<1>(actual) == expectedNumPartitions);
    }
}

void testQuicksortOperationsCounterNumComparisons1() {
    std::vector<int> unordered{1};
    std::vector<int> expectedOrdered{1};
    int expectedNumComparisons = 2;
    std::tuple<std::vector<int>, int, int, int> actual = quicksortOperationsCounter(unordered);
    assert(arraysAreEqual(std::get<0>(actual), expectedOrdered));
    assert(std::get<2>(actual) == expectedNumComparisons);
}

void testQuicksortOperationsCounterNumComparisons2() {
    std::vector<int> unordered{5, 4};
    std::vector<int> expectedOrdered{4, 5};
    int expectedNumComparisons = 5;
    std::tuple<std::vector<int>, int, int, int> actual = quicksortOperationsCounter(unordered);
    assert(arraysAreEqual(std::get<0>(actual), expectedOrdered));
    assert(std::get<2>(actual) == expectedNumComparisons);
}

void testQuicksortOperationsCounterNumSwaps1() {
    std::vector<int> unordered{1};
    std::vector<int> expectedOrdered{1};
    int expectedNumSwaps = 0;
    std::tuple<std::vector<int>, int, int, int> actual = quicksortOperationsCounter(unordered);
    assert(arraysAreEqual(std::get<0>(actual), expectedOrdered));
    assert(std::get<3>(actual) == expectedNumSwaps);
}
void testQuicksortOperationsCounterNumSwaps2() {
    std::vector<int> unordered{5, 6};
    std::vector<int> expectedOrdered{5, 6};
    int expectedNumSwaps = 0;
    std::tuple<std::vector<int>, int, int, int> actual = quicksortOperationsCounter(unordered);
    assert(arraysAreEqual(std::get<0>(actual), expectedOrdered));
    assert(std::get<3>(actual) == expectedNumSwaps);
}

int main() {
    testQuicksort1();
    testQuicksort2();
    testQuicksort10();
    testQuicksortOperationsCounterNumPartitionsFrom1To5();
    testQuicksortOperationsCounterNumComparisons1();
    testQuicksortOperationsCounterNumComparisons2();
    testQuicksortOperationsCounterNumSwaps1();
    testQuicksortOperationsCounterNumSwaps2();
    std::cout << "All tests passed!\n";
    exit(0);
}
