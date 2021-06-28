#include <iostream>
#include "Input.h"

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

template <typename T>
void print_vec(std::vector<T> vec)
{
    for(const auto &val : vec)
    {
        std::cout << val << std::endl;
    }
    std::cout << std::endl;
}
