#ifndef __BITSUMGENERATOR_H__
#define __BITSUMGENERATOR_H__

#include <string>
#include <vector>
#include <unordered_map>

/**
 * @brief 
 * This class is repsonsible for generating a lookup table
 * that maps 0-9 character to 8bit pattern.
 * 
 */

class BitSumGenerator
{
public:
   static std::unordered_map<char, char> Generate();

};

#endif