#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <filesystem>
#include <fstream>

#include "mergesort.h"
#include "quicksort.h"
#include "utils.h"
#include "Timer.h"
#include "Data.h"

namespace fs = std::filesystem;

Data mergesortMain(int maxLengthMergesort) {
    Data data;
    data.header = "\
vectorLength,\
actualNumComparisons,\
expectedNumComparisons,\
timeElapsed\n\
";
    Timer timer;
    int numIterations = maxLengthMergesort;
    for (int n = 1; n < numIterations; ++n) {
        if (n % (numIterations / 10) == 0) {
            std::cout << "Mergesort: " << static_cast<float>(n) / numIterations * 100 << "%.\n";
        }
        std::vector<int> unordered = getRandomVector(n);
        timer.tic();
        std::pair<std::vector<int>, int> result = mergesortComparisonCounter(unordered);
        timer.toc();
        double timeElapsed = timer.getElapsed() / 1e6;
        int actualNumComparisons = result.second;
        double log2n = std::log2(n);
        double expectedNumComparisons = 2. * n + n * floor(log2n) - pow(2, floor(log2n) + 1);
        std::vector<double> innerVector{
            static_cast<double>(n),
            static_cast<double>(actualNumComparisons), expectedNumComparisons,
            timeElapsed
        };
        data.values.push_back(innerVector);
    }
    return data;
}

double formulaQuicksortNumComparisons(int n) {
    return 2. * (harmonic(n + 1) - 1) * (n + 1);
}

double formulaQuicksortNumSwaps(int n) {
    return 1/3. * harmonic(n + 1) * (n + 1) - 7/9. * (n + 1) + 1/2.;
}

Data quicksortMain(int maxLength) {
    Data data;
    data.header = "\
vectorLength,\
actualAverageNumPartitions,expecteAverageNumPartitions,\
actualAverageNumComparisons,expectedAverageNumComparisons,\
actualAverageNumSwaps,expectedAverageNumSwaps\n\
";
    for (int i = 1; i < maxLength + 1; ++i) {
        std::cout << "Quicksort n: " << i << '\n';
        int vectorLength = i;
        std::vector<int> randomVector = getRandomVector(i);
        std::vector<std::vector<int>> allPermutations = getAllPermutations(randomVector);
        int numAllPermutations = allPermutations.size();
        std::vector<int> allNumPartitions(numAllPermutations, 0);
        std::vector<int> allNumComparisons(numAllPermutations, 0);
        std::vector<int> allNumSwaps(numAllPermutations, 0);
        for (int j = 0; j < numAllPermutations; ++j) {
            std::vector<int> unordered = allPermutations[j];
            std::tuple<std::vector<int>, int, int, int> result = quicksortOperationsCounter(unordered);
            allNumPartitions[j] = std::get<1>(result);
            allNumComparisons[j] = std::get<2>(result);
            allNumSwaps[j] = std::get<3>(result);
        }
        double actualAverageNumPartitions = vectorMean(allNumPartitions);
        double actualAverageNumComparisons = vectorMean(allNumComparisons);
        double actualAverageNumSwaps = vectorMean(allNumSwaps);
        double expectedAverageNumPartitions = i;
        double expectedAverageNumComparisons = formulaQuicksortNumComparisons(i);
        double expectedAverageNumSwaps = formulaQuicksortNumSwaps(i); 
        std::vector<double> innerVector{
            static_cast<double>(vectorLength),
            actualAverageNumPartitions, expectedAverageNumPartitions,
            actualAverageNumComparisons, expectedAverageNumComparisons,
            actualAverageNumSwaps, expectedAverageNumSwaps
        };
        data.values.push_back(innerVector);
    }
    return data;
}

void writeDataToCSV(Data data, std::string filename = "quicksortData.csv") {
    int nRows = data.values.size();
    int nCols = data.values[0].size();

    fs::path dataPath = fs::current_path() /= fs::path("data");
    if (!fs::exists(dataPath)) { fs::create_directory(dataPath); }
    fs::path filenamePath = dataPath /= fs::path(filename);

    std::ofstream file(filenamePath);
    file << data.header;
    for (int i = 0; i < nRows; ++i) {
        for (int j = 0; j < nCols - 1; ++j) {
            file << data.values[i][j] << ',';
        }
        file << data.values[i][nCols - 1] << '\n';
    }
    file.close();
}

int main(int argc, char* argv[]) {
    int maxLengthMergesort = 100;
    int maxLengthQuicksort = 8;
    if (argc > 1) {
        std::string firstArg = std::string(argv[1]);
        if (firstArg == "-m") { maxLengthMergesort = std::stoi(argv[2]); }
        if (firstArg == "-q") { maxLengthQuicksort = std::stoi(argv[2]); }
        if (argc > 3) {
            std::string secondArg = std::string(argv[3]);
            if (secondArg == "-m") { maxLengthMergesort = std::stoi(argv[4]); }
            if (secondArg == "-q") { maxLengthQuicksort = std::stoi(argv[4]); }
        }
    }

    Data dataMergesort = mergesortMain(maxLengthMergesort);
    Data dataQuicksort = quicksortMain(maxLengthQuicksort);
    writeDataToCSV(dataQuicksort, "quicksortData.csv");
    writeDataToCSV(dataMergesort, "mergesortData.csv");

    exit(0);
}
