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

    std::vector<std::bitset<32>> message_block = blocking(message);
    std::string res = digest_block(message_block);

    std::cout << res << std::endl;
   
    return 0;
}
//bf6024d0a96d92b6d835f5b408ac49d17bcc0c43efeae6881c61a010779dd098
//bf6024d0a96d92b6d835f5b408ac49d17bcc0c43efeae6881c61a010779dd098