//
// Created by 19711 on 2024/2/24.
//

#ifndef CPP_HSE_IMAGE_H
#define CPP_HSE_IMAGE_H

#include <cstdint>
#include <cstddef>
#include <vector>
#include <iostream>

#include "Color.h"

class Image {
public:
    Image() = default;
    Image(size_t width, size_t height);
    explicit Image(const std::vector<std::vector<Color>>& data);
    Image(const Image& other);
    ~Image() = default;

    size_t GetWidth() const;
    size_t GetHeight() const;
    const std::vector<std::vector<Color>>& GetData() const;
    const Color& GetColor(size_t x, size_t y) const;
    Color& GetColor(size_t x, size_t y);

    void SetColor(size_t x, size_t y, const Color& color);

private:
    size_t width_ = 0;
    size_t height_ = 0;
    std::vector<std::vector<Color>> pixels_;

    void CheckWidthAndHeight(size_t width, size_t height) const;
};

#endif  // CPP_HSE_IMAGE_H
