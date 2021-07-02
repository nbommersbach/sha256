#pragma once

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <bitset>

using byte = std::bitset<8>;

std::vector<byte> to_ascii(std::string str);
std::string padding_512bits(std::vector<byte> &input_binary);
std::vector<std::bitset<32>> blocking(std::string &message);

template <typename T>
void print_vec(std::vector<T> vec)
{
    for(const auto &val : vec)
    {
        std::cout << val << std::endl;
    }
    std::cout << std::endl;
}