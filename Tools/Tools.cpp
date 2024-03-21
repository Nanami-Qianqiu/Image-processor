//
// Created by 19711 on 2024/3/16.
//

#include "Tools.h"

int tools::ArgToInt(const std::string& str) {
    for (const char& c : str) {
        if (!std::isalnum(c)) {
            throw std::invalid_argument("Arg to int: Argument is not a number.");
        }
    }
    return std::stoi(str);
}

double tools::ArgToDouble(const std::string& str) {
    for (const char& c : str) {
        if (!std::isalnum(c) && c != '.') {
            throw std::invalid_argument("Arg to double: Argument is not a number.");
        }
    }
    return std::stod(str);
}

uint8_t tools::Round(double value) {
    return static_cast<uint8_t>(std::round(value));
}

uint8_t tools::GetCorrectColorValue(int value) {
    if (value < image::utils::MIN_RGB_VALUE) {
        return image::utils::MIN_RGB_VALUE;
    } else if (value > image::utils::MAX_RGB_VALUE) {
        return image::utils::MAX_RGB_VALUE;
    }
    return static_cast<uint8_t>(value);
}
