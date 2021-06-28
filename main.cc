#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <bitset>

#include "Input.h"

typedef std::bitset<8> byte;

std::string message;


int main()
{
    std::getline(std::cin, message);

    std::vector<byte> result = to_ascii(message);


    return 0;
}