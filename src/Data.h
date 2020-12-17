#pragma once

#include <string>
#include <vector>
#include <iostream>

struct Data {
    std::string header;
    std::vector<std::vector<double>> values;
};
void printData(Data data);
