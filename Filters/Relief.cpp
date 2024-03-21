//
// Created by 19711 on 2024/3/19.
//

#include "Filter.h"

filter::Relief::Relief(const std::vector<std::string> &args) : Filter(args) {
}

Image filter::Relief::Apply(const Image &image) const {
    uint8_t relief_strength = tools::ArgToInt(GetArgs()[0]);
    std::vector<std::vector<int>> matrix = GetReliefMatrix(relief_strength);
    Image new_image(image.GetWidth(), image.GetHeight());
    ReliefAlgorithm(image, new_image, matrix);

    return new_image;
}
std::vector<std::vector<int>> filter::Relief::GetReliefMatrix(uint8_t relief_strength) const {
    std::vector<std::vector<int>> matrix(relief_strength, std::vector<int>(relief_strength, 0));
    matrix[0][0] = 1;
    matrix[relief_strength - 1][relief_strength - 1] = -1;
    return matrix;
}

void filter::Relief::ReliefAlgorithm(const Image &image, Image &new_image,
                                     const std::vector<std::vector<int>> &matrix) const {
    for (size_t i = 0; i < image.GetHeight(); ++i) {
        for (size_t j = 0; j < image.GetWidth(); ++j) {
            auto pix_colors = GetPixColor<int>(matrix, image, j, i);
            new_image.SetColor(j, i,
                               {tools::GetCorrectColorValue(pix_colors[0] + RELIEF_VALUE),
                                tools::GetCorrectColorValue(pix_colors[1] + RELIEF_VALUE),
                                tools::GetCorrectColorValue(pix_colors[2] + RELIEF_VALUE)});
        }
    }
}
