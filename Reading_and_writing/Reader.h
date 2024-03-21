//
// Created by 19711 on 2024/2/24.
//

#ifndef CPP_HSE_READER_H
#define CPP_HSE_READER_H

#include <string>

#include "../Image/Image.h"

namespace reading_and_writing {
class Reader {
public:
    explicit Reader(const std::string& filename);
    Image Read();

private:
    std::string path_;
    size_t BytesToRead(unsigned char* bytes) const;
};

const size_t GetPaddingSize(size_t width);
}  // namespace reading_and_writing

#endif  // CPP_HSE_READER_H
