#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <bitset>

#include "Preprocessing.h"
#include "Functions.h"

std::string message;

int main()
{
    std::getline(std::cin, message);
    std::vector<byte> input_binary = to_ascii(message);           
    message.clear();
    message = padding_512bits(input_binary);

    std::string res = sha256(message);

    std::cout << res << std::endl;
   
    return 0;
}
