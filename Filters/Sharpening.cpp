//
// Created by 19711 on 2024/3/16.
//

#include "Filter.h"

Image filter::Sharpening::Apply(const Image &image) const {
    std::vector<std::vector<Color>> new_image_data;
    const std::vector<std::vector<int>> matrix = {{0, -1, 0}, {-1, 5, -1}, {0, -1, 0}};
    for (size_t i = 0; i < image.GetHeight(); ++i) {
        std::vector<Color> row(image.GetWidth());
        for (size_t j = 0; j < image.GetWidth(); ++j) {
            auto pix_colors = GetPixColor<int>(matrix, image, j, i);
            row[j] = {tools::GetCorrectColorValue(pix_colors[0]), tools::GetCorrectColorValue(pix_colors[1]),
                      tools::GetCorrectColorValue(pix_colors[2])};
        }
        new_image_data.push_back(row);
    }
    return Image{new_image_data};
}
