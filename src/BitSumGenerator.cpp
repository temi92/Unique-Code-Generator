#include "BitSumGenerator.h"


std::unordered_map<char, char> BitSumGenerator::Generate()
{   

    std::unordered_map<char, char> res;
    res['0'] = 0b01110111;
    res['1'] = 0b01000010;
    res['2'] = 0b10110110;
    res['3'] = 0b11010110;
    res['4'] = 0b11000011;
    res['5'] = 0b11010101;
    res['6'] = 0b11110101;
    res['7'] = 0b01000110;
    res['8'] = 0b11110111;
    res['9'] = 0b11010111;
    return res;


}