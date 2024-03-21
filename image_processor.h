//
// Created by 19711 on 2024/3/16.
//

#ifndef CPP_HSE_IMAGE_PROCESSOR_H
#define CPP_HSE_IMAGE_PROCESSOR_H

#include "Reading_and_writing/Reader.h"
#include "Reading_and_writing/Writer.h"
#include "Reading_and_writing/Utils.h"
#include "Parser/Parser.h"
#include "Image/Image.h"
#include "Filters/Filter.h"

#include <iostream>
#include <chrono>

std::vector<parser::Token> GetTokens(int argc, char** argv);

Image GetImage(const std::string& path);

void WriteImage(const std::string& path, const Image& image);

Image ApplyFilter(Image& image, const std::vector<parser::Token>& tokens);

#endif  // CPP_HSE_IMAGE_PROCESSOR_H
