#ifndef __PNGPARSER_H__
#define __PNGPARSER_H__

#include <png.h>
/**
 * @brief 
 * This class is responsible for handling operations relating to generating the png file format
 * for the pixel data.
 * 
 */

class PngParser
{
public:
    PngParser(png_uint_32 width, png_uint_32 height, int stride);
    bool WritePNG(const char* filename, unsigned char* image);
private:
    png_uint_32 width;
    png_uint_32 height;
    int stride;
};

#endif