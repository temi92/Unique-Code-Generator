#include <string>
#include <gtest/gtest.h>
#include "CheckSumGenerator.h"
#include "PngParser.h"



TEST(UCGTEST, ApplyCheckSumTest)
{
    std::string asset_id = "1337";
    CheckSumGenerator csg;
    EXPECT_EQ(csg.ApplyCheckSum(asset_id), "561337");
    
}


TEST(UCGTEST, PngWriterTest)
{
    png_uint_32 width = 256;
    png_uint_32 height = 1;
    int stride  = 1;
    char c = 0b11111111;
    
    int image_width = width/8;
    unsigned char image[image_width];
    const char* filename = "output.png";
    for (size_t i =0; i < image_width;i++)
    {
        image[i] = c;
    }
  
    PngParser parser(width, height, stride);
    ASSERT_TRUE(parser.WritePNG(filename, image));
    

}
