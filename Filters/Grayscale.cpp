//
// Created by 19711 on 2024/3/16.
//

#include "Filter.h"

Image filter::Grayscale::Apply(const Image &image) const {
    std::vector<std::vector<Color>> new_image_data;
    for (size_t i = 0; i < image.GetHeight(); ++i) {
        std::vector<Color> row(image.GetWidth());
        for (size_t j = 0; j < image.GetWidth(); ++j) {
            auto value = static_cast<uint8_t>(GRAYSCALE_BLUE_PARAMETER * image.GetColor(j, i).blue +
                                              GRAYSCALE_GREEN_PARAMETER * image.GetColor(j, i).green +
                                              GRAYSCALE_RED_PARAMETER * image.GetColor(j, i).red);
            row[j] = {value, value, value};
        }
        new_image_data.push_back(row);
    }
    return Image{new_image_data};
}
