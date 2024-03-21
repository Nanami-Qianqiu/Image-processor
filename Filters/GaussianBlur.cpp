//
// Created by 19711 on 2024/3/17.
//

#include "Filter.h"

filter::GaussianBlur::GaussianBlur(const std::vector<std::string>& args) : Filter(args) {
    // TODO: error detection
}

Image filter::GaussianBlur::Apply(const Image& image) const {
    Image temp_image(image);
    double sigma = tools::ArgToDouble(GetArgs()[0]);
    std::vector<double> kernel = GetGaussianKernel(sigma);
    for (size_t i = 0; i < image.GetHeight(); ++i) {
        for (size_t j = 0; j < image.GetWidth(); ++j) {
            double blue = 0;
            double green = 0;
            double red = 0;
            for (int x = static_cast<int>(j) - GAUSSIAN_BLUR_RADIUS; x <= static_cast<int>(j) + GAUSSIAN_BLUR_RADIUS;
                 ++x) {
                size_t dx = abs(static_cast<int>(x) - static_cast<int>(j));
                int valid_x = x;
                if (valid_x < 0) {
                    valid_x = -x;
                } else if (valid_x >= static_cast<int>(image.GetWidth())) {
                    valid_x = 2 * static_cast<int>(image.GetWidth()) - 1 - x;
                }
                blue += kernel[dx] * image.GetColor(valid_x, i).blue_d;
                green += kernel[dx] * image.GetColor(valid_x, i).green_d;
                red += kernel[dx] * image.GetColor(valid_x, i).red_d;
            }
            temp_image.SetColor(j, i, Color{blue, green, red});
        }
    }
    Image result_image(temp_image);
    for (size_t i = 0; i < image.GetHeight(); ++i) {
        for (size_t j = 0; j < image.GetWidth(); ++j) {
            double blue = 0;
            double green = 0;
            double red = 0;
            for (int y = static_cast<int>(i) - GAUSSIAN_BLUR_RADIUS; y <= static_cast<int>(i) + GAUSSIAN_BLUR_RADIUS;
                 ++y) {
                size_t dy = abs(static_cast<int>(y) - static_cast<int>(i));
                int valid_y = y;
                if (valid_y < 0) {
                    valid_y = -y;
                } else if (valid_y >= static_cast<int>(image.GetHeight())) {
                    valid_y = 2 * static_cast<int>(image.GetHeight()) - 1 - y;
                }
                blue += kernel[dy] * temp_image.GetColor(j, valid_y).blue_d;
                green += kernel[dy] * temp_image.GetColor(j, valid_y).green_d;
                red += kernel[dy] * temp_image.GetColor(j, valid_y).red_d;
            }
            result_image.SetColor(j, i, Color{blue, green, red});
        }
    }
    return result_image;
}

std::vector<double> filter::GaussianBlur::GetGaussianKernel(double sigma) const {
    std::vector<double> kernel(GAUSSIAN_BLUR_RADIUS + 1);
    for (size_t i = 0; i <= GAUSSIAN_BLUR_RADIUS; ++i) {
        kernel[i] =
            exp(-static_cast<double>(i) * static_cast<double>(i) / (2 * sigma * sigma)) / (sigma * sqrt(2 * M_PI));
    }
    return kernel;
}