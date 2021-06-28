#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <bitset>

#include "Input.h"

std::string message;

int main()
{
    std::getline(std::cin, message);
    std::vector<byte> result = to_ascii(message);
    print_vec<byte>(result);

    return 0;
}