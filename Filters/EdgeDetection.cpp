//
// Created by 19711 on 2024/3/16.
//

#include "Filter.h"

filter::EdgeDetection::EdgeDetection(const std::vector<std::string>& args) : Filter(args) {
}

Image filter::EdgeDetection::Apply(const Image& image) const {
    const std::vector<std::vector<int>> matrix = {{0, -1, 0}, {-1, 4, -1}, {0, -1, 0}};
    const double threshold = tools::ArgToDouble(GetArgs()[0]);
    std::unique_ptr<filter::Filter> gs_filter = std::make_unique<filter::Grayscale>();
    Image gs_image = gs_filter->Apply(image);
    std::vector<std::vector<Color>> new_image_data;
    for (size_t i = 0; i < gs_image.GetHeight(); ++i) {
        std::vector<Color> row(gs_image.GetWidth());
        for (size_t j = 0; j < gs_image.GetWidth(); ++j) {
            std::vector<int> pix_colors = GetPixColor<int>(matrix, gs_image, j, i);
            const double pix_double_value = static_cast<double>(pix_colors[0]) / image::utils::MAX_RGB_VALUE;
            if (pix_double_value > threshold) {
                row[j] = {image::utils::MAX_RGB_VALUE, image::utils::MAX_RGB_VALUE, image::utils::MAX_RGB_VALUE};
            } else {
                row[j] = {image::utils::MIN_RGB_VALUE, image::utils::MIN_RGB_VALUE, image::utils::MIN_RGB_VALUE};
            }
        }
        new_image_data.push_back(row);
    }
    return Image(new_image_data);
}
