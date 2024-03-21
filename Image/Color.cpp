//
// Created by 19711 on 2024/3/15.
//

#include "Color.h"

Color::Color(uint8_t blue_in, uint8_t green_in, uint8_t red_in) : blue(blue_in), green(green_in), red(red_in) {
    blue_d = blue;
    green_d = green;
    red_d = red;
}

Color::Color(double blue_in, double green_in, double red_in) : blue_d(blue_in), green_d(green_in), red_d(red_in) {
    blue = tools::Round(blue_in);
    green = tools::Round(green_in);
    red = tools::Round(red_in);
}

void Color::SetVals(uint8_t blue_in, uint8_t green_in, uint8_t red_in) {
    blue = blue_in;
    green = green_in;
    red = red_in;
    blue_d = blue;
    green_d = green;
    red_d = red;
}

uint8_t Color::GetBlue() const {
    return blue;
}

uint8_t Color::GetGreen() const {
    return green;
}

uint8_t Color::GetRed() const {
    return red;
}
