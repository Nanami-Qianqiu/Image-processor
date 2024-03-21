//
// Created by 19711 on 2024/3/16.
//

#ifndef CPP_HSE_TOOLS_H
#define CPP_HSE_TOOLS_H

#include <string>
#include <stdexcept>
#include <cstdint>
#include <cmath>

#include "../Reading_and_writing/Utils.h"

namespace tools {
int ArgToInt(const std::string& str);

double ArgToDouble(const std::string& str);

uint8_t Round(double value);

uint8_t GetCorrectColorValue(int value);
}  // namespace tools

#endif  // CPP_HSE_TOOLS_H
