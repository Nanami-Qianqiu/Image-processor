//
// Created by 19711 on 2024/3/16.
//

#include "Filter.h"

Image filter::Negative::Apply(const Image &image) const {
    std::vector<std::vector<Color>> new_image_data;
    for (size_t i = 0; i < image.GetHeight(); ++i) {
        std::vector<Color> row(image.GetWidth());
        for (size_t j = 0; j < image.GetWidth(); ++j) {
            row[j] = {static_cast<uint8_t>(image::utils::MAX_RGB_VALUE - image.GetColor(j, i).blue),
                      static_cast<uint8_t>(image::utils::MAX_RGB_VALUE - image.GetColor(j, i).green),
                      static_cast<uint8_t>(image::utils::MAX_RGB_VALUE - image.GetColor(j, i).red)};
        }
        new_image_data.push_back(row);
    }
    return Image{new_image_data};
}
