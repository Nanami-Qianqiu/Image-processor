//
// Created by 19711 on 2024/3/9.
//

#ifndef CPP_HSE_FILTER_H
#define CPP_HSE_FILTER_H

#include <algorithm>
#include <memory>
#include <cmath>
#include <chrono>

#include "../Image/Image.h"
#include "../Reading_and_writing/Utils.h"
#include "../Parser/Parser.h"
#include "../Tools/Tools.h"
#include "FilterConstants.h"

namespace filter {
class Filter {
public:
    Filter();
    explicit Filter(const std::vector<std::string>& args);
    virtual ~Filter();
    virtual Image Apply(const Image& image) const = 0;
    const std::vector<std::string>& GetArgs() const;

private:
    std::vector<std::string> args_;

protected:
    template <typename T>
    std::vector<T> GetPixColor(const std::vector<std::vector<T>>& matrix, const Image& image, size_t x, size_t y) const;

    static std::chrono::time_point<std::chrono::system_clock> start_time;
};

class Negative : public Filter {
public:
    Image Apply(const Image& image) const override;
};

class Grayscale : public Filter {
public:
    Image Apply(const Image& image) const override;
};

class Sharpening : public Filter {
public:
    Image Apply(const Image& image) const override;
};

class EdgeDetection : public Filter {
public:
    explicit EdgeDetection(const std::vector<std::string>& args);
    Image Apply(const Image& image) const override;
};

class Crop : public Filter {
public:
    explicit Crop(const std::vector<std::string>& args);
    Image Apply(const Image& image) const override;
};

class GaussianBlur : public Filter {
public:
    explicit GaussianBlur(const std::vector<std::string>& args);
    Image Apply(const Image& image) const override;

protected:
    std::vector<double> GetGaussianKernel(double sigma) const;
};

class Relief : public Filter {
public:
    explicit Relief(const std::vector<std::string>& args);
    Image Apply(const Image& image) const override;

private:
    std::vector<std::vector<int>> GetReliefMatrix(uint8_t relief_strength) const;
    void ReliefAlgorithm(const Image& image, Image& new_image, const std::vector<std::vector<int>>& matrix) const;
};

std::unique_ptr<Filter> GetFilter(const parser::Token& token);
}  // namespace filter

template <typename T>
std::vector<T> filter::Filter::GetPixColor(const std::vector<std::vector<T>>& matrix, const Image& image, size_t x,
                                           size_t y) const {
    T red = 0;
    T green = 0;
    T blue = 0;
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix.front().size(); ++j) {
            size_t new_x = std::min(std::max(0, static_cast<int>(x) + static_cast<int>(j) - 1),
                                    static_cast<int>(image.GetWidth()) - 1);
            size_t new_y = std::min(std::max(0, static_cast<int>(y) + static_cast<int>(i) - 1),
                                    static_cast<int>(image.GetHeight()) - 1);
            red += matrix[i][j] * image.GetColor(new_x, new_y).red;
            green += matrix[i][j] * image.GetColor(new_x, new_y).green;
            blue += matrix[i][j] * image.GetColor(new_x, new_y).blue;
        }
    }
    return {blue, green, red};
}
#endif  // CPP_HSE_FILTER_H
