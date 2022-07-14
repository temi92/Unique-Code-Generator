#ifndef __CHECKSUMGENERATOR_H__
#define __CHECKSUMGENERATOR_H__

#include <string>
#include <vector>
#include <array>
/**
 * @brief 
 * This class implements a simple checksum by using modular arithmetic with a base of 97
 * 
 */
class CheckSumGenerator
{
public:
    CheckSumGenerator() = default;
    CheckSumGenerator(const std::vector<std::string>& asset_ids) ;
    std::string ApplyCheckSum(const std::string& id);
    std::vector<std::string> GetCheckSumIds() {return asset_ids;}

private:
   int toInt(char c);
   std::vector<std::string> asset_ids;
   std::array<int, 3> nums { 10, 100, 1000};
};

#endif