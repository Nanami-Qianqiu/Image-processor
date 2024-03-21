//
// Created by 19711 on 2024/3/15.
//

#include "Image.h"

Image::Image(size_t width, size_t height)
    : width_(width), height_(height), pixels_(std::vector<std::vector<Color>>(height, std::vector<Color>(width))) {
}

Image::Image(const std::vector<std::vector<Color>>& data)
    : width_(data.empty() ? 0 : data[0].size()), height_(data.size()), pixels_(data) {
}

Image::Image(const Image& other) : width_(other.width_), height_(other.height_), pixels_(other.pixels_) {
}

size_t Image::GetWidth() const {
    return width_;
}

size_t Image::GetHeight() const {
    return height_;
}

const std::vector<std::vector<Color>>& Image::GetData() const {
    return pixels_;
}

const Color& Image::GetColor(size_t x, size_t y) const {
    CheckWidthAndHeight(x, y);
    return pixels_[y][x];
}

Color& Image::GetColor(size_t x, size_t y) {
    CheckWidthAndHeight(x, y);
    return pixels_[y][x];
}

void Image::CheckWidthAndHeight(size_t width, size_t height) const {
    if (width >= width_ || height >= height_) {
        throw std::invalid_argument(std::string("x and y out of range while getting color"));
    }
}
void Image::SetColor(size_t x, size_t y, const Color& color) {
    CheckWidthAndHeight(x, y);
    pixels_[y][x] = color;
}
