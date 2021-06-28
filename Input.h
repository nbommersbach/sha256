#pragma once

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <bitset>

using byte = std::bitset<8>;

std::vector<byte> to_ascii(std::string str);

template <typename T>
void print_vec(std::vector<T> vec)
{
    for(const auto &val : vec)
    {
        std::cout << val << std::endl;
    }
    std::cout << std::endl;
}

