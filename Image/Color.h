//
// Created by 19711 on 2024/2/24.
//

#pragma once

#include <cstdint>
#include "../Reading_and_writing/Utils.h"
#include "../Tools/Tools.h"

struct Color {
    uint8_t blue = 0;
    uint8_t green = 0;
    uint8_t red = 0;
    double blue_d = 0;
    double green_d = 0;
    double red_d = 0;
    Color() = default;
    Color(uint8_t blue_in, uint8_t green_in, uint8_t red_in);
    Color(double blue_in, double green_in, double red_in);

    uint8_t GetBlue() const;
    uint8_t GetGreen() const;
    uint8_t GetRed() const;

    void SetVals(uint8_t blue_in, uint8_t green_in, uint8_t red_in);
};
