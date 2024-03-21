//
// Created by 19711 on 2024/2/24.
//

#ifndef CPP_HSE_UTILS_H
#define CPP_HSE_UTILS_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdint>

namespace image::utils {
const int BMP_HEADER_SIZE = 14;
const int DIB_HEADER_SIZE = 40;
const int PADDING_BYTES = 4;
const int BYTES_PER_PIXEL = 3;
const int HEADER_WIDTH_OFFSET = 4;
const int HEADER_HEIGHT_OFFSET = 8;
const int HEADER_FILE_SIZE_OFFSET = 2;
const int PIXEL_ARRAY_OFFSET = 10;
const int FILE_FORMAT_FIRST_POSITION = 0;
const int FILE_FORMAT_SECOND_POSITION = 1;
const int INFORMATION_HEADER_SIZE_POSITION = 0;
const int COLOR_PLANES = 1;
const int COLOR_PLANES_OFFSET = 12;
const int BITS_PER_PIXEL = 24;
const int BITS_PER_PIXEL_POSITION = 14;
const int RELIEF_VALUE = 128;
const uint8_t MAX_RGB_VALUE = 255;
const uint8_t MIN_RGB_VALUE = 0;
const double MAX_RGB_DOUBLE_VALUE = 1;
const double MIN_RGB_DOUBLE_VALUE = 0;

const std::vector<int> SHIFT_BITS = {8, 16, 24};
const std::vector<char> HEADER_SIGNATURE = {'B', 'M'};
}  // namespace image::utils

#endif  // CPP_HSE_UTILS_H
