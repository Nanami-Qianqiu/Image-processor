//
// Created by 19711 on 2024/3/4.
//

#ifndef CPP_HSE_WRITER_H
#define CPP_HSE_WRITER_H

#include <algorithm>
#include <cerrno>
#include <string>
#include <utility>
#include <fstream>

#include "../Image/Image.h"
#include "Utils.h"
#include "Reader.h"

namespace reading_and_writing {
class Writer {
public:
    explicit Writer(const std::string filename);
    void Write(const Image& image);

private:
    void WriteDIBHeader(unsigned char* dib_header, size_t width, size_t height);
    void WriteBMPHeader(unsigned char* bmp_header, size_t file_size);

    template <typename T>
    void WriteBytes(T number, unsigned char* bytes);

    std::string path_;
};
}  // namespace reading_and_writing

#endif  // CPP_HSE_WRITER_H
