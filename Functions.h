#include <iostream>
#include <cmath>
#include <bitset>
#include <vector>
#include <sstream>
#include <iomanip>

//names according to NIST

std::bitset<32> rotright(std::bitset<32> &input, const unsigned int rots);
std::bitset<32> rotleft(std::bitset<32> &input, const unsigned int rots);

unsigned long ch(unsigned long xl, unsigned long yl, unsigned long zl);
unsigned long maj(unsigned long xl, unsigned long yl, unsigned long zl);
unsigned long bsig0(unsigned long xl);
unsigned long bsig1(unsigned long xl);
unsigned long ssig0(unsigned long xl);
unsigned long ssig1(unsigned long xl);

std::string hex_return(unsigned long input);
std::string digest_block(std::vector<std::bitset<32>> &m);