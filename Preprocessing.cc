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
    std::size_t k;
    uint64_t l;

    // check l < 2^64

    for(const auto &val : input_binary)
    {
        message.append(val.to_string());
    }

    l = message.size();
    message.append("1");

    k = 448 - l - 1;
    k = k % 512;

    for(std::size_t i = 0; i < k; ++i)
    {
        message.append("0");
    }

    std::bitset<64> l_64bits(l);
    message.append(l_64bits.to_string());

    std::cout << "Message_length: " << message.size() << std::endl;
    std::cout << std::hex << "Message: " << message << std::endl;

    return message;
}