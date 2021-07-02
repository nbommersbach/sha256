#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <bitset>

#include "Constants.h"
#include "Preprocessing.h"

std::string message;

int main()
{
    std::getline(std::cin, message);
    std::vector<byte> input_binary = to_ascii(message);           
    message.clear();

    message = padding_512bits(input_binary);
    

    return 0;
}