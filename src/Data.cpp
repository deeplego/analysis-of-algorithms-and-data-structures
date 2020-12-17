#include "Data.h"

void printData(Data data) {
    int nRows = data.values.size();
    int nCols = data.values[0].size();
    std::cout << data.header;
    for (int i = 0; i < nRows; ++i) {
        for (int j = 0; j < nCols - 1; ++j) {
            std::cout << data.values[i][j] << ", ";
        }
        std::cout << data.values[i][nCols - 1] << '\n';
    }
}
