#include <iostream>
#include <fstream>
#include <png.h>
#include <string>
#include <vector>
#include "CheckSumGenerator.h"
#include "BitSumGenerator.h"
#include "PngParser.h"
#include <stdlib.h>
using namespace std;

void SetImageToDefaults(unsigned char *image, size_t size, char default_value)
{
  for (size_t i = 0; i < size; i++)
  {
    image[i] = default_value;
  }
}

int main(int argc , char**argv)
 
{

  string id;
  vector<string> asset_ids;
  ifstream input_file("../Resources/test.txt");
  png_uint_32 width = 256;// image width in pixels, each pixel is one bit.
  png_uint_32 height = 1; //image height in pixels
  int stride = 1;
  int size = width/8;
  unsigned char image [size];
  PngParser png_writer(width, height, stride);

  while (getline (input_file,id )) 
  {
    asset_ids.push_back(id);
  }

  if (asset_ids.size()== 0)
  {
    std::cerr << "file is empty " << endl;
    return -1;
  }

  CheckSumGenerator csg(asset_ids);
  const vector<string> checksum_ids = csg.GetCheckSumIds();
  const auto lookup_table  = BitSumGenerator::Generate();
 
  for (const auto &checksum_id: checksum_ids)
  {
      int start_index = 1;
      // initialize the 256 bit pattern to 1 for all the bits.
      SetImageToDefaults(image, size, 0b11111111);
      for (const auto & c: checksum_id)
      {
        image[start_index] = ~lookup_table.at(c);
        start_index +=1 ;
       
      } 
      std::string filename = checksum_id + ".png";
      png_writer.WritePNG(filename.c_str(), image);
     
  }
 
  return 0;

}




