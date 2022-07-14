#include "PngParser.h"


PngParser::PngParser(png_uint_32 width, png_uint_32 height, int stride):
width(width), height(height), stride(stride)
{


}


bool  PngParser::WritePNG(const char* filename, unsigned char* image)
{
    /**
     * @brief 
     * responsible for generating the png file. refer to http://www.libpng.org/pub/png/libpng-1.2.5-manual.html on using libpng library.
     * @param filename path to png file to be written too
     * @param image pointer to pixel data
     * 
     * @return bool returns true if the write operations succeeds.
     */
    FILE* out_file = fopen(filename, "w");
    png_structp png;
    png_infop info;
    png_uint_32 y;

    png = png_create_write_struct(PNG_LIBPNG_VER_STRING,
                                NULL, NULL, NULL);
    if (png == NULL) 
    {
        return false;
    }
    info = png_create_info_struct(png);
    if (info == NULL) 
    {
        png_destroy_write_struct(&png, NULL);
        return false;
    }
    if (setjmp(png_jmpbuf(png)))
    {
        png_destroy_write_struct(&png, &info);
        return 0;
    }
    png_init_io(png, out_file);

  
    png_set_IHDR(png, info, width, height, 1,
               PNG_COLOR_TYPE_GRAY,
               PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_DEFAULT,
               PNG_FILTER_TYPE_DEFAULT);
    
    png_write_info(png, info);
    for (y = 0; y < height; ++y)
    {
        png_bytep row = image + y * stride;
        png_write_rows(png, &row, 1);
    }
    png_write_end(png, info);
    png_destroy_write_struct(&png, &info);
    return true;



}
