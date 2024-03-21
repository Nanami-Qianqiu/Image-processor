//
// Created by 19711 on 2024/3/16.
//

#include "Filter.h"

filter::Crop::Crop(const std::vector<std::string> &args) : Filter(args) {
}

Image filter::Crop::Apply(const Image &image) const {
    size_t new_width = std::min(static_cast<size_t>(tools::ArgToInt(GetArgs()[0])), image.GetWidth());
    size_t new_height = std::min(static_cast<size_t>(tools::ArgToInt(GetArgs()[1])), image.GetHeight());

    std::vector<std::vector<Color>> new_image_data;
    for (size_t i = 0; i < new_height; ++i) {
        std::vector<Color> row(new_width);
        for (size_t j = 0; j < new_width; ++j) {
            row[j] = image.GetColor(j, image.GetHeight() + i - new_height);
        }
        new_image_data.push_back(row);
    }
    return Image(new_image_data);
}
