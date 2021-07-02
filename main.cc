#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <bitset>

#include "Constants.h"
#include "Preprocessing.h"
#include "Functions.h"

std::string message;

int main()
{
    /* std::getline(std::cin, message);
    std::vector<byte> input_binary = to_ascii(message);           
    message.clear();

    message = padding_512bits(input_binary); */

    std::bitset<32> a ("11000000000011110111011110111010");
    std::cout << a << std::endl;

    std::cout << ssig0(a) << std::endl;

    return 0;
}