#include "image_processor.h"

int main(int argc, char** argv) {
    try {
        const auto start = std::chrono::high_resolution_clock::now();
        std::vector<parser::Token> tokens = GetTokens(argc, argv);
        Image image = GetImage(tokens[0].name);
        image = ApplyFilter(image, tokens);
        WriteImage(tokens[1].name, image);
        const auto end = std::chrono::high_resolution_clock::now();
        const auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        std::cout << "Program execution time: " << duration.count() << " ms" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}

std::vector<parser::Token> GetTokens(int argc, char** argv) {
    std::vector<parser::Token> tokens = parser::Parse(argc, argv);
    if (tokens.size() < 2) {
        throw std::invalid_argument("Not enough arguments");
    }
    return tokens;
}

Image GetImage(const std::string& path) {
    reading_and_writing::Reader reader(path);
    Image image = reader.Read();
    return image;
}

void WriteImage(const std::string& path, const Image& image) {
    reading_and_writing::Writer writer(path);
    writer.Write(image);
}

Image ApplyFilter(Image& image, const std::vector<parser::Token>& tokens) {
    for (size_t i = 2; i < tokens.size(); ++i) {
        image = filter::GetFilter(tokens[i])->Apply(image);
    }
    return image;
}
