cmake_minimum_required(VERSION 3.27)
project(Image_processor)

set(CMAKE_CXX_STANDARD 20)

add_executable(
        image_processor
        image_processor.cpp
        Filters/Crop.cpp
        Filters/EdgeDetection.cpp
        Filters/Filter.cpp
        Filters/Filter.h
        Filters/GaussianBlur.cpp
        Filters/Negative.cpp
        Filters/Sharpening.cpp
        Reading_and_writing/Reader.h
        Reading_and_writing/Reader.cpp
        Filters/Grayscale.cpp
        Image/Image.cpp
        Image/Image.h
        Image/Color.cpp
        Image/Color.h
        Parser/Parser.cpp
        Parser/Parser.h
        Reading_and_writing/Writer.cpp
        Reading_and_writing/Writer.h
        Reading_and_writing/Utils.h
        Tools/Tools.cpp
        Tools/Tools.h
        image_processor.h
        Filters/Relief.cpp
        Filters/FilterConstants.h
        Filters/FilterConstants.h
)

