#pragma once

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <bitset>

typedef std::bitset<8> byte;

std::vector<byte> to_ascii(std::string str);

template <typename T>
void print_vec(std::vector<T> vec);

