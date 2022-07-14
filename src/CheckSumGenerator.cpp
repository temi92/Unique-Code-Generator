#include "CheckSumGenerator.h"
#include <iostream>


CheckSumGenerator:: CheckSumGenerator(const std::vector<std::string>& ids)
{
    for (const auto& id: ids)
    {
        std::string checksum_id = ApplyCheckSum(id);
        asset_ids.push_back(checksum_id);
    }
}


std::string CheckSumGenerator::ApplyCheckSum(const std::string& id)
{
    /**
     * @brief applies a checksum useful for error detection.
     * @param id input string to apply checksum to.
     * @return generated checksum id.
     * 
     */
    int result = 0;
    for (size_t i = 0; i < id.size(); i++)
    {
        if (i == 0)
        {
            result += toInt(id[i]);
        }
        else
        {
            result += nums[i-1] * toInt(id[i]);
        }

    }
    result = result % 97;
    // take into account if we have only single digits after performing the modulus operation, for such cases we just append 0 to the leading edge.
    std::string cs = (result < 10)? "0" + std::to_string(result) + id : std::to_string(result) + id;
    return cs;
}
int CheckSumGenerator::toInt(char c)
{
    /**
     * @brief convert char to integer see https://www.ascii-code.com/
     * @param  c  input to be converted to integer
     * @return  returned integer value
     */
    return c - '0';
}


