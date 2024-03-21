//
// Created by 19711 on 2024/3/9.
//

#include "Filter.h"

filter::Filter::Filter(const std::vector<std::string> &args) : args_(args) {
}

const std::vector<std::string> &filter::Filter::GetArgs() const {
    return args_;
}

filter::Filter::Filter() {
    start_time = std::chrono::system_clock::now();
    std::cout << "Filter started" << std::endl;
}
filter::Filter::~Filter() {
        std::chrono::time_point<std::chrono::system_clock> end_time = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end_time - start_time;
        std::cout << "Filter finished in " << elapsed_seconds.count() << " seconds" << std::endl;
}

std::unique_ptr<filter::Filter> filter::GetFilter(const parser::Token &token) {
    const std::string &name = token.name;
    if (name == "-neg") {
        if (!token.args.empty()) {
            throw std::invalid_argument("Negative filter doesn't take any arguments");
        }
        std::unique_ptr<filter::Filter> filter = std::make_unique<filter::Negative>();
        return filter;
    } else if (name == "-sharp") {
        if (!token.args.empty()) {
            throw std::invalid_argument("Sharpening filter doesn't take any arguments");
        }
        std::unique_ptr<filter::Filter> filter = std::make_unique<filter::Sharpening>();
        return filter;
    } else if (name == "-gs") {
        if (!token.args.empty()) {
            throw std::invalid_argument("Grayscale filter doesn't take any arguments");
        }
        std::unique_ptr<filter::Filter> filter = std::make_unique<filter::Grayscale>();
        return filter;
    } else if (name == "-edge") {
        if (token.args.size() != 1) {
            throw std::invalid_argument("Edge detection: filter requires only one argument");
        } else if (tools::ArgToDouble(token.args[0]) < image::utils::MIN_RGB_DOUBLE_VALUE ||
                   tools::ArgToDouble(token.args[0]) > image::utils::MAX_RGB_DOUBLE_VALUE) {
            throw std::invalid_argument("Edge detection: Threshold value should be in range [0, 1]");
        }
        std::unique_ptr<filter::Filter> filter = std::make_unique<filter::EdgeDetection>(token.args);
        return filter;
    } else if (name == "-crop") {
        if (token.args.size() != 2) {
            throw std::invalid_argument("Crop filter requires two arguments");
        }
        std::unique_ptr<filter::Filter> filter = std::make_unique<filter::Crop>(token.args);
        return filter;
    } else if (name == "-blur") {
        if (token.args.size() != 1) {
            throw std::invalid_argument("Gaussian Blur: filter requires only one argument");
        } else if (tools::ArgToDouble(token.args[0]) < image::utils::MIN_RGB_DOUBLE_VALUE) {
            throw std::invalid_argument("Gaussian Blur: Sigma value should be positive");
        }
        std::unique_ptr<filter::Filter> filter = std::make_unique<filter::GaussianBlur>(token.args);
        return filter;
    } else if (name == "-relief") {
        if (token.args.size() != 1) {
            throw std::invalid_argument("Relief filter requires one argument");
        } else if (tools::ArgToInt(token.args[0]) < MIN_RELIEF_STRENGTH ||
                   tools::ArgToInt(token.args[0]) > MAX_RELIEF_STRENGTH) {
            throw std::invalid_argument("Relief filter: strength should be in range [1, 10]");
        }
        std::unique_ptr<filter::Filter> filter = std::make_unique<filter::Relief>(token.args);
        return filter;
    } else {
        throw std::invalid_argument("Unknown filter " + name);
    }
}
