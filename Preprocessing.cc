#include <iostream>
#include "Preprocessing.h"

std::vector<byte> to_ascii(std::string str)
{
    std::vector<byte> vec;

    for(const auto val : str)
    {
        byte res = int(val);
        vec.push_back(res);
    }

    return vec;
}

std::string padding_512bits(std::vector<byte> &input_binary)
{
    std::string message;
    std::size_t k_val;
    uint64_t l;

    // check l < 2^64

    for(const auto &val : input_binary)
    {
        message.append(val.to_string());
    }

    l = message.size();
    message.append("1");

    k_val = 448 - l - 1;
    k_val = k_val % 512;

    for(std::size_t i = 0; i < k_val; ++i)
    {
        message.append("0");
    }

    std::bitset<64> l_64bits(l);
    message.append(l_64bits.to_string());

    return message;
}

std::vector<std::bitset<32>> blocking(std::string &message)
{
    std::vector<std::bitset<32>> result;
    message = message.substr(0, 512);

    for(unsigned int i = 0; i < 16; ++i)
    {
        unsigned long lower = 32 * i;
        result.push_back(std::bitset<32>(message.substr(lower, lower + 32)));
    }

    return result;
}